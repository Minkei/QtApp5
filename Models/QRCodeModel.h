#ifndef QRCODEMODEL_H
#define QRCODEMODEL_H

#include <QAbstractListModel>
#include <QVector>
#include "QRCodeData.h"

class QRCodeModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit QRCodeModel(QObject *parent = nullptr);

    enum QRCodeRoles {
        IdRole = Qt::UserRole + 1,
        ContentRole,
        ScannedDayRole,
        ScannedTimeRole,
        PicRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addQRCode(const QRCodeData &data);
    QVector<QRCodeData> getQRCodes() const;
    void clearQRCodes();
    bool contains(const QString &content) const;
    void printQRCodes() const ;

signals:
    void qrCodeAdded(const QRCodeData &data);
    void qrCodesCleared();

private:
    QVector<QRCodeData> m_qrCodes;
};

#endif // QRCODEMODEL_H
