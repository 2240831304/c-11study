#include "mainwindow.h"
#include <QTime>
#include <QDebug>
#include <QStringList>

#include "testclass.h"

class MainWindowPrivate
{
public:
    BaseClass *baseTest;

};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),d(new MainWindowPrivate)
{
    resize(800,600);

    d->baseTest->printfNum(36);
    int retnum = d->baseTest->getNum();
    //QString retString = d->baseTest->getString();
    //qDebug() << "MainWindow jhhhhhhhhh===" << retString;
}

MainWindow::~MainWindow()
{
    if(d){
        delete d;
        d = nullptr;
    }

}
