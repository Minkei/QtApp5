#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>

class MainViewModel : public QObject 
{
    Q_OBJECT

public:
    explicit MainViewModel(QObject *parent = nullptr);

public slots:
    Q_INVOKABLE void logoutByViewModel();

signals:
    void logoutSucces();
};

#endif // MAINVIEWMODEL_H
