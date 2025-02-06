#include "QRScannerViewModel.h"
#include <QDateTime>
#include <QtMultimedia>
#include <QCamera>

QRScannerViewModel::QRScannerViewModel(QObject *parent) 
    : QObject(parent),
    m_timer(new QTimer(this))
{
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &QRScannerViewModel::updateDateTime);
    m_timer->start();

    // Initialize current date and time
    updateDateTime();

    // Initialize camera list
    initializeCameras();
}



QString QRScannerViewModel::currentDate() const
{
    return m_currentDate;
}

QString QRScannerViewModel::currentTime() const
{
    return m_currentTime;
}

QStringList QRScannerViewModel::availableCameras() const{
    return m_availableCameras;
}

QString QRScannerViewModel::selectedCamera() const
{
    return m_selectedCamera;
}

void QRScannerViewModel::setSelectedCamera(const QString &camera)
{
    if(m_selectedCamera != camera) {
        m_selectedCamera = camera;
        emit selectedCameraChanged();
    }
}

void QRScannerViewModel::updateDateTime()
{
    QDateTime now = QDateTime::currentDateTime();

    QString newDate = now.toString("dd/MM/yyyy");
    if(m_currentDate != newDate) {
        m_currentDate = newDate;
        emit currentDateChanged();
    }

    QString newTime = now.toString("HH:mm:ss");
    if(m_currentDate != newTime) {
        m_currentTime = newTime;
        emit currentTimeChanged();
    }
}


void QRScannerViewModel::initializeCameras() {
    m_availableCameras.clear();
    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();
    for(const QCameraDevice &cameraDevice : cameras) {
        m_availableCameras.append(cameraDevice.description());
    }

    if(m_availableCameras.isEmpty())
    {
        emit cameraError("No cameras available");
    }
    else if(m_selectedCamera.isEmpty()) {
        setSelectedCamera(m_availableCameras.first());
    }
    emit availableCamerasChanged();
}


void QRScannerViewModel::refreshCameraList()
{
    initializeCameras();
}
