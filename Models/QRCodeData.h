#ifndef QRCODEDATA_H
#define QRCODEDATA_H

#include <QString>
#include <QDateTime>

class QRCodeData
{
public:
    QRCodeData(const QString &content, const QString &pic);

    QString id() const;
    QString content() const;
    QString scannedDay() const;
    QString scannedTime() const;
    QString pic() const;

private:
    QString m_id;
    QString m_content;
    QString m_scannedDay;
    QString m_scannedTime;
    QString m_pic;
};

#endif // QRCODEDATA_H
