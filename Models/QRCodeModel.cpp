#include "QRCodeModel.h"

QRCodeModel::QRCodeModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // addQRCode("Hello", "sdfdsf");
}

int QRCodeModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_qrCodes.count();
}

QVariant QRCodeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_qrCodes.count())
        return QVariant();

    const QRCodeData &data = m_qrCodes[index.row()];

    switch (role) {
    case IdRole:
        return data.id();
    case ContentRole:
        return data.content();
    case ScannedDayRole:
        return data.scannedDay();
    case ScannedTimeRole:
        return data.scannedTime();
    case PicRole:
        return data.pic();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> QRCodeModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[ContentRole] = "content";
    roles[ScannedDayRole] = "scannedDay";
    roles[ScannedTimeRole] = "scannedTime";
    roles[PicRole] = "pic";
    return roles;
}

void QRCodeModel::addQRCode(const QRCodeData &data)
{
    if (contains(data.content())) {
        qDebug() << "Duplicate QR code: " << data.content();
        return; // Skip duplicate QR code
    }

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_qrCodes.append(data);
    endInsertRows();
    emit qrCodeAdded(data);
    qDebug() << "QR code added: " << data.content();
}

QVector<QRCodeData> QRCodeModel::getQRCodes() const
{
    return m_qrCodes;
}

void QRCodeModel::clearQRCodes()
{
    beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
    m_qrCodes.clear();
    endRemoveRows();
    emit qrCodesCleared();
    qDebug() << "QR codes cleared";
}

bool QRCodeModel::contains(const QString &content) const
{
    for (const QRCodeData &data : m_qrCodes) {
        if (data.content() == content) {
            return true;
        }
    }
    return false;
}

void QRCodeModel::printQRCodes() const
{
    for (const QRCodeData &data : m_qrCodes) {        
        qDebug() << "ID: " << data.id() << ", Content: " << data.content() << ", Scanned Day: " << data.scannedDay() << ", Scanned Time: " << data.scannedTime() << ", Pic: " << data.pic();
    }
}
