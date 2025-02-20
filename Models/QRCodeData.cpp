#include "QRCodeData.h"
#include <QUuid>

QRCodeData::QRCodeData(const QString &content, const QString &pic)
    : m_id(QUuid::createUuid().toString())
    , m_content(content)
    , m_scannedDay(QDate::currentDate().toString(Qt::ISODate))
    , m_scannedTime(QTime::currentTime().toString(Qt::ISODate))
    , m_pic(pic)
{
}

QString QRCodeData::id() const
{
    return m_id;
}

QString QRCodeData::content() const
{
    return m_content;
}

QString QRCodeData::scannedDay() const
{
    return m_scannedDay;
}

QString QRCodeData::scannedTime() const
{
    return m_scannedTime;
}

QString QRCodeData::pic() const
{
    return m_pic;
}
