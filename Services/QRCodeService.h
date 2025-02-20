#ifndef QRCODESERVICE_H
#define QRCODESERVICE_H

#include <QObject>
#include <QString>
#include <QImage>
#include <ZXing/ReadBarcode.h>
#include <ZXing/DecodeHints.h>
#include <ZXing/Barcode.h>
#include <ZXing/ImageView.h>



class QRCodeService : public QObject
{
    Q_OBJECT

public:
    explicit QRCodeService(QObject *parent = nullptr);
    QString decodeImage(const QImage &image);

signals:
    void qrCodeDecoded(const QString &qrCodeData);

};

#endif // QRCODESERVICE_H
