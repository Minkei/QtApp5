#ifndef CAMERASERVICE_H
#define CAMERASERVICE_H

#include <QObject>
#include <QCamera>
#include <QVideoSink>
#include <QMediaCaptureSession>
#include <QtMultimedia>
#include <QVideoFrame>


class CameraService : public QObject
{
    Q_OBJECT

public:
    explicit CameraService(QObject *parent = nullptr);
    void startCamera();
    void stopCamera();
    void setVideoSink(QVideoSink *videoSink);
    bool isStreaming() const;
    void setCamera(const QString &cameraName);

signals:
    void cameraError(const QString &error);
    void cameraStarted();
    void cameraStopped();
    void frameCaptured(const QVideoFrame &frame);

private slots:
    void handleCameraError(QCamera::Error error, const QString &errorString);
    void handleFrameCaptured(const QVideoFrame &frame);

private:
    QCamera *m_camera;
    QMediaCaptureSession m_captureSession;
};
    

#endif // CAMERASERVICE_H
