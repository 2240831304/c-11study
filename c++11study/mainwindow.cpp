#include "mainwindow.h"
#include <QTime>
#include <QDebug>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    QString tempStr = "[00:23.88]走在铁路旁";
//    QStringList list = tempStr.split(QRegExp("[\[\\]]"));
//    //QStringList list = tempStr.split(QRegExp("[0-9]{2}"));
//    //list << "W@W2" << "wsw";
//    qDebug() << list;
    int lenth = 3088;
    int hour = lenth / 3600;
    QTime time(0,0,0,0);
    QString str;
    time = time.addMSecs(lenth);
    if(hour > 0)
        str = time.toString("hh:mm:ss");
    else
        str = time.toString("mm:ss");
    qDebug() << "555555555555555===" << str << time.second();
}

MainWindow::~MainWindow()
{

}
