#include "QRScannerViewModel.h"
#include <QtConcurrent>

QRScannerViewModel::QRScannerViewModel(QObject *parent) : QObject{parent}, 
    m_isStreaming(false), 
    m_cameraService(new CameraService(this)),
    m_qrCodeService(new QRCodeService(this)),
    m_videoSink(nullptr)
{
    refreshCameraList();

    // Date and time
    connect(&m_timer, &QTimer::timeout, this, &QRScannerViewModel::updateDateTime);
    m_timer.start(1000);

    // Camera
    connect(m_cameraService, &CameraService::cameraError, this, &QRScannerViewModel::handleCameraError);
    connect(m_cameraService, &CameraService::frameCaptured, this, &QRScannerViewModel::processFrame); 

    // QRCode
    connect(m_qrCodeService, &QRCodeService::qrCodeDecoded, this, [this](const QString &qrCodeData) { 
        m_qrCodeData = qrCodeData; 
        emit qrCodeDataChanged();
    });  
}

// Properties
QString QRScannerViewModel::currentDate() const {
    return QDateTime::currentDateTime().toString("dd.MM.yyyy");
}

QString QRScannerViewModel::currentTime() const {
    return QDateTime::currentDateTime().toString("hh:mm:ss");
}

QStringList QRScannerViewModel::availableCameras() const {  
    return m_availableCameras;
}

QString QRScannerViewModel::selectedCamera() const {
    return m_selectedCamera;
}

bool QRScannerViewModel::isStreaming() const {
    // return m_cameraService->isStreaming();
    return m_isStreaming;
}

bool QRScannerViewModel::isLoading() const {
    // return m_cameraService->isLoading();
    return m_isLoading;
}

QVideoSink *QRScannerViewModel::videoSink() const {
    return m_videoSink;
}

QString QRScannerViewModel::qrCodeData() const
{
    return m_qrCodeData;
}

QString QRScannerViewModel::qrCodeDataLatest() const
{
    return m_qrCodeDataLatest;
}

// Methods
void QRScannerViewModel::toggleStreaming() {
    if(m_availableCameras.isEmpty()) {
        return;
    }

    if(!m_isStreaming) {
        m_isLoading = true;
        emit isLoadingChanged();

        qDebug() << "Starting camera...";
        qDebug() << "isStreaming: " << m_isStreaming;
        qDebug() << "isLoading: " << m_isLoading;

        m_cameraService->setCamera(m_selectedCamera);
        // m_cameraService->startCamera();

        QTimer::singleShot(0, m_cameraService, &CameraService::startCamera);

        m_isStreaming = true;
        m_isLoading = false;

        emit isLoadingChanged();
        emit isStreamingChanged();

        qDebug() << "Selected camera: " << m_selectedCamera;
        qDebug() << "Camera started!";
        qDebug() << "isStreaming: " << m_isStreaming;
        qDebug() << "isLoading: " << m_isLoading;

    }
    else {
        m_cameraService->stopCamera();
        m_isStreaming = false;
    }
    emit isStreamingChanged();
}

void QRScannerViewModel::refreshCameraList() {
    m_availableCameras.clear();
    const auto cameras = QMediaDevices::videoInputs();
    for (const auto &camera : cameras) {
        m_availableCameras.append(camera.description());
    }
    emit availableCamerasChanged();

}

void QRScannerViewModel::setSelectedCamera(const QString &camera) {
    if (m_selectedCamera != camera) {
        m_selectedCamera = camera;
        emit selectedCameraChanged();
    }
}

void QRScannerViewModel::handleCameraError(const QString &errorMessage) {
    emit cameraErrorOccured(errorMessage);
}

void QRScannerViewModel::updateDateTime() {
    emit currentDateChanged();
    emit currentTimeChanged();
}

void QRScannerViewModel::setVideoSink(QVideoSink *videoSink) { 

    if(m_videoSink != videoSink) {
        m_videoSink = videoSink;

        if(m_cameraService) {
            m_cameraService->setVideoSink(videoSink);
        }
        emit videoSinkChanged();
    }
    if(!isStreaming()) {
        if(m_videoSink) {
            m_videoSink->setVideoFrame(QVideoFrame());
        }
    }
}   

void QRScannerViewModel::processFrame(const QVideoFrame &frame) {
    if(!frame.isValid()) {
        qDebug() << "Invalid frame received";
        return;
    }

    QImage image = frame.toImage();
    if(image.isNull()) {
        qDebug() << "Failed to convert frame to image";
        return;
    }

    m_isLoading = true;
    emit isLoadingChanged();
    
    QThreadPool::globalInstance()->start([this, image](){
        QString result = m_qrCodeService->decodeImage(image);

        m_qrCodeData = result;
        emit qrCodeDataChanged();

        if(!result.isEmpty() && result != m_qrCodeDataLatest && result != "No QR Code detected") {
            m_qrCodeDataLatest = result;
            emit qrCodeDataLatestChanged();
            qDebug() << "QRCode Latest: " << m_qrCodeDataLatest;
        }
        m_isLoading = false;
        emit isLoadingChanged();
    });
}
