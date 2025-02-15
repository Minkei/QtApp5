#include "CameraService.h"

CameraService::CameraService(QObject *parent) : QObject(parent), m_camera(new QCamera(parent)) {
    m_captureSession.setCamera(m_camera);
    connect(m_camera, &QCamera::errorOccurred, this, &CameraService::handleCameraError);
}

void CameraService::setVideoSink(QVideoSink *videoSink) {
    if(videoSink) {
        m_captureSession.setVideoOutput(videoSink);
    }
}

bool CameraService::isStreaming() const {
    return m_camera && m_camera->isActive();    
}

void CameraService::startCamera() {
    if(m_camera && !isStreaming()) {
        // qDebug() << "Starting camera...";
        m_camera->start();
        // qDebug() << "Camera selected: " << m_camera->cameraDevice().description();
        // qDebug() << "Camera state" << m_camera->isActive();
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

void CameraService::handleCameraError(QCamera::Error error, const QString &errorString) {
    if(error != QCamera::NoError) {
        emit cameraError(errorString);
    }
}   
