#include "CameraService.h"

CameraService::CameraService(QObject *parent) : QObject(parent), m_camera(new QCamera(parent)) {
    m_captureSession.setCamera(m_camera);
    connect(m_camera, &QCamera::errorOccurred, this, &CameraService::handleCameraError);
}

void CameraService::setVideoSink(QVideoSink *videoSink) {
    if(videoSink) {
        m_captureSession.setVideoOutput(videoSink);
        connect(videoSink, &QVideoSink::videoFrameChanged, this, &CameraService::handleFrameCaptured);
    }
}

bool CameraService::isStreaming() const {
    return m_camera && m_camera->isActive();    
}

void CameraService::startCamera() {
    if(m_camera && !isStreaming()) {
        m_camera->start();
    }
}   

void CameraService::stopCamera() {
    if(m_camera && isStreaming()) {
        m_camera->stop();
        // m_camera->deleteLater();
    }
}

void CameraService::setCamera(const QString &cameraName) {
    const auto cameras = QMediaDevices::videoInputs();
    for (const auto &camera : cameras) {
        if (camera.description() == cameraName) {
            m_camera->setCameraDevice(camera);
        }
    }
}

void CameraService::handleFrameCaptured(const QVideoFrame &frame)
{
    emit frameCaptured(frame);
}

void CameraService::handleCameraError(QCamera::Error error, const QString &errorString) {
    if(error != QCamera::NoError) {
        emit cameraError(errorString);
    }
}   
