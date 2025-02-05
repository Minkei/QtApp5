#ifndef USERMODEL_H
#define USERMODEL_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QSettings>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>

class UserModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString displayName READ displayName WRITE setDisplayName NOTIFY displayNameChanged)
    Q_PROPERTY(QString photoUrl READ photoUrl WRITE setPhotoUrl NOTIFY photoUrlChanged)
    Q_PROPERTY(bool emailVerified READ emailVerified WRITE setEmailVerified NOTIFY emailVerifiedChanged)
    Q_PROPERTY(QString idToken READ idToken WRITE setIdToken NOTIFY idTokenChanged)
    Q_PROPERTY(QString localId READ localId WRITE setLocalId NOTIFY localIdChanged)

public:
    static UserModel& getInstance();

    // Getters
    QString email() const;
    QString displayName() const;
    QString photoUrl() const;
    bool emailVerified() const;
    QString idToken() const;
    QString localId() const;

public slots:
    // Setters
    void setEmail(const QString &email);
    void setDisplayName(const QString &displayName);
    void setPhotoUrl(const QString &photoUrl);
    void setEmailVerified(bool emailVerified);
    void setIdToken(const QString &idToken);
    void setLocalId(const QString &localId);

    // Methods
    void updateFromJson(const QJsonObject &jsonObject);
    void clearUserData();
    void saveToSetting();
    void loadFromSetting();

signals:
    void emailChanged();
    void displayNameChanged();
    void photoUrlChanged();
    void emailVerifiedChanged();
    void idTokenChanged();
    void localIdChanged();


private:
    explicit UserModel(QObject *parent = nullptr);
    UserModel(const UserModel&) = delete;
    UserModel& operator=(const UserModel&) = delete;

    QString m_email;
    QString m_displayName;
    QString m_photoUrl;
    bool m_emailVerified;
    QString m_idToken;
    QString m_localId;

    bool isTokenValid(const QString &token);
};


#endif // USERMODEL_H

