#ifndef LISTENMSGTHREAD_H
#define LISTENMSGTHREAD_H

#include <QObject>
#include <QThread>
#include <iostream>
#include "ros/ros.h"
#include "pacman/Num.h"
#include "pacman/glwidget.h"

using namespace std;

class ListenMsgThread : public QThread
{
    Q_OBJECT
    
    void run();
public:
    ListenMsgThread();
    void callback0(const pacman::Num::ConstPtr& msg);
    void callback1(const pacman::Num::ConstPtr& msg);
    void setWorkingThread(bool aWork);
           
private:
    bool work;
    
signals:
    void UpdatePacmanCommand(int action, int id);
};

#endif // LISTENMSGTHREAD_H