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
    // Get only one instance of CameraService
    static CameraService* instance() {
        static CameraService *s_instance = new CameraService();
        return s_instance;
    }

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
    // Constructor được đặt là private để chỉ cho phép truy cập qua instance()
    explicit CameraService(QObject *parent = nullptr);
    // Vô hiệu hóa copy constructor và assignment operator
    CameraService(const CameraService&) = delete;
    CameraService& operator=(const CameraService&) = delete;
    QCamera *m_camera;
    QMediaCaptureSession m_captureSession;
};
    

#endif // CAMERASERVICE_H
