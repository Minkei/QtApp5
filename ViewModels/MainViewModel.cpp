#include "MainViewModel.h"
#include <QObject>
#include <Models/UserModel.h>

MainViewModel::MainViewModel(QObject *parent) : QObject(parent)
{
    m_cameraService = CameraService::instance();
}

void MainViewModel::logoutByViewModel()
{
    
    if(m_cameraService) {
        qDebug() << "Stopped camera by Logout";
        m_cameraService->stopCamera();
    }
    UserModel::getInstance().clearUserData();
    emit logoutSucces();


}
