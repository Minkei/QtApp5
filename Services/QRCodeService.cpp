#include "QRCodeService.h"
#include <QDebug>
#include <QThread>

QRCodeService::QRCodeService(QObject *parent) : QObject(parent)
{
}

QString QRCodeService::decodeImage(const QImage &image)
{
    if(image.isNull()) {
        qWarning() << "Invalid image!";
        QString result = "Invalid image";
        emit qrCodeDecoded(result);
        return result;
    }

    // Convert QImage to ZXing ImageView format
    QImage img = image.convertToFormat(QImage::Format_RGBA8888);
    ZXing::ImageView zxingImage(img.bits(), img.width(), img.height(), ZXing::ImageFormat::RGBA);

    // Set decode hints
    ZXing::ReaderOptions options;
    options.setTryHarder(true);
    options.setFormats(ZXing::BarcodeFormat::QRCode);

    // Decode the QR code
    ZXing::Result result = ZXing::ReadBarcode(zxingImage, options);

    QString resultText;
    if (result.isValid()) {
        resultText = QString::fromStdString(result.text());
    } else {
        resultText = "No QR Code detected";
    }

    emit qrCodeDecoded(resultText);
    return resultText;
}
