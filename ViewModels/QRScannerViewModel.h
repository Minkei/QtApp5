#ifndef QRSCANNERVIEWMODEL_H
#define QRSCANNERVIEWMODEL_H

#include <QObject>
#include <QString>
#include <QTimer>
#include <QStringList>
#include <QtMultimedia>
#include <QCamera>

class QRScannerViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentDate READ currentDate NOTIFY currentDateChanged FINAL)
    Q_PROPERTY(QString currentTime READ currentTime NOTIFY currentTimeChanged FINAL)
    Q_PROPERTY(QStringList availableCameras READ availableCameras NOTIFY availableCamerasChanged FINAL)
    Q_PROPERTY(QString selectedCamera READ selectedCamera WRITE setSelectedCamera NOTIFY selectedCameraChanged FINAL)
    
public:
    explicit QRScannerViewModel(QObject *parent = nullptr);

    QString currentDate() const;
    QString currentTime() const;
    QStringList availableCameras() const;
    QString selectedCamera() const;

public slots:
    void setSelectedCamera(const QString &camera);
    void refreshCameraList();

signals:
    void currentDateChanged();
    void currentTimeChanged();
    void availableCamerasChanged();
    void selectedCameraChanged();
    void cameraError(const QString &error);


private slots:
    void updateDateTime();

private:
    QString m_currentDate;
    QString m_currentTime;

    QTimer *m_timer;

    void initializeCameras();
    QStringList m_availableCameras;
    QString m_selectedCamera;
};

#endif // QRSCANNERVIEWMODEL_H
