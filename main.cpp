// main.cpp
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <ViewModels/LoginViewModel.h>
#include <ViewModels/MainViewModel.h>
#include <Models/UserModel.h>
#include <ViewModels/QRScannerViewModel.h>
#include <Services/QRCodeService.h>



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QCoreApplication::setOrganizationName("IMAS");
    QCoreApplication::setApplicationName("QRScanner");

    LoginViewModel loginViewModel;
    MainViewModel mainViewModel;
    QRScannerViewModel qrScannerViewModel;
    
    UserModel::getInstance().clearUserData();
    UserModel::getInstance().loadFromSetting(); 

    engine.rootContext()->setContextProperty("loginViewModel", &loginViewModel);
    engine.rootContext()->setContextProperty("mainViewModel", &mainViewModel);
    engine.rootContext()->setContextProperty("qrScannerViewModel", &qrScannerViewModel);
    engine.rootContext()->setContextProperty("userModel", &UserModel::getInstance());


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("QtApp5", "Main");

    return app.exec();
}
