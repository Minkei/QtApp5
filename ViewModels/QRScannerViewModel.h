#ifndef QRSCANNERVIEWMODEL_H
#define QRSCANNERVIEWMODEL_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <QDateTime>
#include <QtMultimedia>
#include <QVideoSink>

#include <Services/CameraService.h>
#include <Services/QRCodeService.h>



class QRScannerViewModel : public QObject
{
    Q_OBJECT
    
    // Date and time
    Q_PROPERTY(QString currentDate READ currentDate NOTIFY currentDateChanged)
    Q_PROPERTY(QString currentTime READ currentTime NOTIFY currentTimeChanged)

    // Camera 
    Q_PROPERTY(QStringList availableCameras READ availableCameras NOTIFY availableCamerasChanged)
    Q_PROPERTY(QString selectedCamera READ selectedCamera WRITE setSelectedCamera NOTIFY selectedCameraChanged)
    Q_PROPERTY(bool isStreaming READ isStreaming NOTIFY isStreamingChanged)
    Q_PROPERTY(bool isLoading READ isLoading NOTIFY isLoadingChanged)
    Q_PROPERTY(QVideoSink* videoSink READ videoSink WRITE setVideoSink NOTIFY videoSinkChanged)

    // QRCode
    Q_PROPERTY(QString qrCodeData READ qrCodeData NOTIFY qrCodeDataChanged)
    Q_PROPERTY(QString qrCodeDataLatest READ qrCodeDataLatest NOTIFY qrCodeDataLatestChanged)


public:
    explicit QRScannerViewModel(QObject *parent = nullptr);

    // Date and time properties
    QString currentDate() const;
    QString currentTime() const;

    // Camera properties
    QStringList availableCameras() const;
    QString selectedCamera() const;
    bool isStreaming() const;
    bool isLoading() const;
    QVideoSink *videoSink() const;

    // QRCode properties
    QString qrCodeData() const;
    QString qrCodeDataLatest() const;
    
    // Methods
    Q_INVOKABLE void setSelectedCamera(const QString &camera);
    Q_INVOKABLE void refreshCameraList();
    Q_INVOKABLE void toggleStreaming();
    Q_INVOKABLE void setVideoSink(QVideoSink *videoSink);


public slots:
    void processFrame(const QVideoFrame &frame);

signals:
    // Date and time
    void currentDateChanged();
    void currentTimeChanged();

    // Camera
    void availableCamerasChanged();
    void selectedCameraChanged();
    void isStreamingChanged();
    void isLoadingChanged();
    void cameraErrorOccured(const QString &errorMessage);
    void videoSinkChanged();

    // QRCode
    void qrCodeDataChanged();
    void qrCodeDataLatestChanged();

private slots:
    void updateDateTime();
    void handleCameraError(const QString &error);

private:
    // Date and time
    QTimer m_timer;

    // Camera
    QStringList m_availableCameras;
    QString m_selectedCamera;
    bool m_isStreaming;
    bool m_isLoading;
    CameraService *m_cameraService;
    QVideoSink *m_videoSink;

    // QRCode
    QRCodeService *m_qrCodeService;
    QString m_qrCodeData;
    QString m_qrCodeDataLatest;

};
#endif // QRSCANNERVIEWMODEL_H
