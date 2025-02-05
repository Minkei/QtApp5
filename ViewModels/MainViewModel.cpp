#include "MainViewModel.h"
#include <QObject>
#include <Models/UserModel.h>

MainViewModel::MainViewModel(QObject *parent) : QObject(parent)
{

}

void MainViewModel::logoutByViewModel()
{
    UserModel::getInstance().clearUserData();
    emit logoutSucces();
}
