#include "mainwindow.h"
#include <QApplication>
#include "testclass.h"
#include "elevenfeature.h"
#include <iostream>
#include <QDebug>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

#if 0
    BaseClass *base = new SubClass;
    delete base;

    qDebug() << " ";

    SubClass *sub = new SubClass;
    delete sub;
#endif

#if 0
    ElevenFeature test;
    test.commonFunction();
    test.conditionFunction();

#endif

    cout << "ssssssssssssssssssssssssss";
    char *str = "eeeeeeeeeeee";

    cout << "3333333333=" << strlen(str) << "sizeof="<< sizeof(str) << endl;
    fprintf(stderr,"1111111111111=%s\n",str);

    return a.exec();
}
