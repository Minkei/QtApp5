// LoginViewModel.h

#ifndef LOGINVIEWMODEL_H
#define LOGINVIEWMODEL_H

#include <QObject>
#include <QString>
#include "../Repositories/FirebaseAuth.h"

class LoginViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorMessageChanged)
    Q_PROPERTY(bool isLoading READ isLoading NOTIFY isLoadingChanged)

public:
    explicit LoginViewModel(QObject *parent = nullptr);

    QString email() const;
    QString password() const;
    QString errorMessage() const;

    void setEmail(const QString &email);
    void setPassword(const QString &password);

    bool isLoading() const { return m_isLoading; }


    Q_INVOKABLE void loginByViewModel();

signals:
    void emailChanged();
    void passwordChanged();
    void errorMessageChanged();
    void loginSuccess();
    void isLoadingChanged();

private:
    QString m_email = "minkeii2211@gmail.com";
    QString m_password = "Khiemminhtran22";
    QString m_errorMessage;

    bool m_isLoading = false;
    bool isValidEmail(const QString &email);

    FirebaseAuth *m_firebaseAuth;

private slots:
    void onLoginSuccess(const QString &idToken);
    void onLoginFailed(const QString &errorMessage);
};

#endif // LOGINVIEWMODEL_H
