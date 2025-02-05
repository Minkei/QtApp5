    // LoginViewModel.cpp

    #include "LoginViewModel.h"
    #include "Models/UserModel.h"

    #include <QDebug>

    LoginViewModel::LoginViewModel(QObject *parent) : QObject(parent) {
        m_firebaseAuth = new FirebaseAuth(this);
        connect(m_firebaseAuth, &FirebaseAuth::loginSuccess, this, &LoginViewModel::onLoginSuccess);
        connect(m_firebaseAuth, &FirebaseAuth::loginFailed, this, &LoginViewModel::onLoginFailed);
    }

    QString LoginViewModel::email() const {
        return m_email;
    }

    QString LoginViewModel::password() const {
        return m_password;
    }

    QString LoginViewModel::errorMessage() const {
        return m_errorMessage;
    }

    void LoginViewModel::setEmail(const QString &email) {
        if (m_email != email) {
            m_email = email;
            emit emailChanged();
        }
    }

    void LoginViewModel::setPassword(const QString &password) {
        if (m_password != password) {
            m_password = password;
            emit passwordChanged();
        }
    }

    bool LoginViewModel::isValidEmail(const QString &email)
    {
        QRegularExpression emailRegex("\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b");
        return emailRegex.match(email).hasMatch();
    }

    void LoginViewModel::loginByViewModel() {
        m_isLoading = true;
        emit isLoadingChanged();
        qDebug() << "loginByViewModel is run!";
        m_firebaseAuth->loginByFirebase(m_email, m_password);
    }

    void LoginViewModel::onLoginSuccess(const QString &idToken) {
        m_isLoading = false;
        emit isLoadingChanged();
        qDebug() << "Login successfully from onLoginSuccess! with token: " << idToken;
        UserModel::getInstance().setIdToken(idToken);

        emit loginSuccess();
    }

    void LoginViewModel::onLoginFailed(const QString &errorMessage) {
        m_isLoading = false;
        emit isLoadingChanged();
        m_errorMessage = errorMessage;
        emit errorMessageChanged();
    }
