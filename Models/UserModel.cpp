#include "UserModel.h"

#include <QDebug>
#include <QThread>

UserModel::UserModel(QObject *parent)
    : QObject(parent)
    , m_emailVerified(false)
{

}

bool UserModel::isTokenValid(const QString &token) {
    if (token.isEmpty()) return false;

    // Decode JWT token (phần giữa của token)
    QStringList tokenParts = token.split('.');
    if (tokenParts.size() != 3) return false;

    // Decode base64
    QByteArray payload = QByteArray::fromBase64(tokenParts[1].toUtf8());
    QJsonDocument doc = QJsonDocument::fromJson(payload);
    QJsonObject obj = doc.object();

    // Lấy thời gian hết hạn
    qint64 expTime = obj["exp"].toInteger();
    qint64 currentTime = QDateTime::currentSecsSinceEpoch();

    return currentTime < expTime;
}

UserModel& UserModel::getInstance()
{
    static UserModel instance;
    return instance;
}

// Getters implementation
QString UserModel::email() const
{
    return m_email;
}

QString UserModel::displayName() const
{
    return m_displayName;
}

QString UserModel::photoUrl() const
{
    return m_photoUrl;
}

bool UserModel::emailVerified() const
{
    return m_emailVerified;
}

QString UserModel::idToken() const
{
    return m_idToken;
}

QString UserModel::localId() const
{
    return m_localId;
}

// Setters implementation
void UserModel::setEmail(const QString &email)
{
    if (m_email == email)
        return;

    m_email = email;
    saveToSetting();
    emit emailChanged();
}

void UserModel::setDisplayName(const QString &displayName)
{
    if (m_displayName == displayName)
        return;

    m_displayName = displayName;
    emit displayNameChanged();
}

void UserModel::setPhotoUrl(const QString &photoUrl)
{
    if (m_photoUrl == photoUrl)
        return;

    m_photoUrl = photoUrl;
    emit photoUrlChanged();
}

void UserModel::setEmailVerified(bool emailVerified)
{
    if (m_emailVerified == emailVerified)
        return;

    m_emailVerified = emailVerified;
    emit emailVerifiedChanged();
}

void UserModel::setIdToken(const QString &idToken)
{
    // qDebug() << "setIdToken called from:" << Q_FUNC_INFO;
    // qDebug() << "Stack trace:";
    // QDebug(QtDebugMsg) << QThread::currentThread()->objectName();
    
    if (m_idToken == idToken)
        return;

    m_idToken = idToken;
    emit idTokenChanged();
}

void UserModel::setLocalId(const QString &localId)
{
    if (m_localId == localId)
        return;

    m_localId = localId;
    emit localIdChanged();
}

// Methods implementation
void UserModel::updateFromJson(const QJsonObject &jsonObject)
{
    if (jsonObject.isEmpty())
        return;

    setEmail(jsonObject.value("email").toString());
    setDisplayName(jsonObject.value("displayName").toString());
    setPhotoUrl(jsonObject.value("photoUrl").toString());
    setEmailVerified(jsonObject.value("emailVerified").toBool());
    setLocalId(jsonObject.value("localId").toString());
    if (jsonObject.contains("idToken") && !jsonObject.value("idToken").toString().isEmpty()) {
        setIdToken(jsonObject.value("idToken").toString());
    }
    saveToSetting();
}

void UserModel::clearUserData()
{
    setEmail("");
    setDisplayName("");
    setPhotoUrl("");
    setEmailVerified(false);
    setIdToken("");
    setLocalId("");

    // Clear settings
    QSettings settings;
    settings.remove("user");
}

void UserModel::saveToSetting()
{
    if(m_idToken.isEmpty())
        return;

    QSettings settings;
    settings.beginGroup("user");
    settings.setValue("email", m_email);
    settings.setValue("displayName", m_displayName);
    settings.setValue("photoUrl", m_photoUrl);
    settings.setValue("emailVerified", m_emailVerified);
    settings.setValue("idToken", m_idToken);
    settings.setValue("localId", m_localId);
    settings.endGroup();
}

void UserModel::loadFromSetting()
{
    QSettings settings;
    settings.beginGroup("user");
    QString saveToken = settings.value("idToken").toString();
    if(!saveToken.isEmpty() && isTokenValid(saveToken)) {
        setIdToken(saveToken);
        setEmail(settings.value("email").toString());
        setDisplayName(settings.value("displayName").toString());
        setPhotoUrl(settings.value("photoUrl").toString());
        setEmailVerified(settings.value("emailVerified").toBool());
        setLocalId(settings.value("localId").toString());
    }
    else {
        clearUserData();
    }
    
    settings.endGroup();
}
