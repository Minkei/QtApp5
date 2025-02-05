// FirebaseAuth.cpp
#include "FirebaseAuth.h"
#include "Models/UserModel.h"

FirebaseAuth::FirebaseAuth(QObject *parent) : QObject(parent) {
    m_networkManager = new QNetworkAccessManager(this);
}

void FirebaseAuth::loginByFirebase(const QString &email, const QString &password) {
    qDebug() << "loginByFirebase is run!";
    QUrl url("https://identitytoolkit.googleapis.com/v1/accounts:signInWithPassword?key=" + apiKey);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["email"] = email;
    json["password"] = password;
    json["returnSecureToken"] = true;

    QNetworkReply *reply = m_networkManager->post(request, QJsonDocument(json).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply](){onLoginFinished(reply);});
}

QString FirebaseAuth::parseFirebaseError(const QString &errorMessage)
{
    if (errorMessage.contains("INVALID_EMAIL")) {
        return "Invalid email format";
    }
    if (errorMessage.contains("INVALID_PASSWORD")) {
        return "Invalid password";
    }
    if (errorMessage.contains("EMAIL_NOT_FOUND")) {
        return "Email not found. Please check your email or sign up";
    }
    if (errorMessage.contains("INVALID_LOGIN_CREDENTIALS")) {
        return "Invalid email or password";
    }
    if (errorMessage.contains("TOO_MANY_ATTEMPTS_TRY_LATER")) {
        return "Too many failed attempts. Please try again later";
    }
    if (errorMessage.contains("EMAIL_EXISTS")) {
        return "Email already exists";
    }
    if (errorMessage.contains("OPERATION_NOT_ALLOWED")) {
        return "Operation not allowed. Please contact support";
    }
    if (errorMessage.contains("WEAK_PASSWORD")) {
        return "Password should be at least 6 characters";
    }
    if (errorMessage.contains("USER_DISABLED")) {
        return "This account has been disabled";
    }
    if (errorMessage.contains("NETWORK_ERROR") || errorMessage.contains("NETWORK_REQUEST_FAILED")) {
        return "Network error. Please check your connection";
    }

    return "An error occurred. Please try again later";
}

void FirebaseAuth::onLoginFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jsonObject = jsonDocument.object();

        
        QString idToken = jsonObject["idToken"].toString();
        UserModel::getInstance().setIdToken(idToken);
        getUserProfile(idToken);
        emit loginSuccess(idToken);
    } else {
        QJsonDocument jsonDocument = QJsonDocument::fromJson(reply->readAll());
        QString errorMessage = jsonDocument.object().value("error").toObject().value("message").toString();
        emit loginFailed(parseFirebaseError(errorMessage));
    }
    reply->deleteLater();
}


// Thêm hàm lấy user profile
void FirebaseAuth::getUserProfile(const QString &idToken) {
    QUrl url("https://identitytoolkit.googleapis.com/v1/accounts:lookup?key=" + apiKey);
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["idToken"] = idToken;

    QNetworkReply *reply = m_networkManager->post(request, QJsonDocument(json).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
            if (jsonDoc.object().contains("users") && !jsonDoc.object()["users"].toArray().isEmpty()) {
                QJsonObject userData = jsonDoc.object()["users"].toArray().first().toObject();
                
                // Cập nhật thông tin user
                UserModel::getInstance().updateFromJson(userData);
            }
        }
        reply->deleteLater();
    });
}