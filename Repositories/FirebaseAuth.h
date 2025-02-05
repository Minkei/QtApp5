//FirebaseAuth.h
#ifndef FIREBASEAUTH_H
#define FIREBASEAUTH_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class FirebaseAuth : public QObject
{
    Q_OBJECT

public:
    explicit FirebaseAuth(QObject *parent = nullptr);
    void loginByFirebase(const QString &email, const QString &password);

signals:
    void loginSuccess(const QString &idToken);
    void loginFailed(const QString &errorMessage);

private:
    QString parseFirebaseError(const QString &errorMessage);
    QNetworkAccessManager *m_networkManager;
    QString apiKey = "AIzaSyDAjhJlGUw1KrwJPpvQkXtP732I3RxvNn4";
    void getUserProfile(const QString &idToken);

private slots:
    void onLoginFinished(QNetworkReply *reply);
};

#endif // FIREBASEAUTH_H
