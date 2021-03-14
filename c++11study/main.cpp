#include "mainwindow.h"
#include <QApplication>
#include "testclass.h"
#include "elevenfeature.h"
#include <iostream>
#include <QDebug>
using namespace std;
#include "memory.h"

void test()
{
        char *p = NULL;
        *p = 'T';
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 0
    test();
#endif


#if 1
    MainWindow w;
    w.show();
#endif

#if 0
    BaseClass *base = new SubClass;
    delete base;

    qDebug() << " ";

    SubClass *sub = new SubClass;
    delete sub;
#endif

#if 0
//    KeywordClass KeywordClass1;
//    KeywordClass1.test();

    DriveKeywordClass DriveKeywordClass1;
    //DriveKeywordClass1.test();
    //DriveKeywordClass1.func();
    //DriveKeywordClass1.func(1);
    //DriveKeywordClass1.lambdafunc();
    DriveKeywordClass1.SmartPointer();


//    const DriveKeywordClass DriveKeywordClass2;
//    DriveKeywordClass2.constfunc();


    //KeywordClass KeywordClass2 = KeywordClass1;

#endif

#if 0
    ElevenFeature test;
    test.commonFunction();
    test.conditionFunction();

#endif

#if 0
    char *str = "eeeeeeeeeeee";

    cout << "3333333333=" << strlen(str) << "  " <<  "sizeof="<< sizeof(str) << endl;
    //fprintf(stderr,"1111111111111=%s\n",str);
    cout << str << endl;

    Test5();
    cout << "ddd";

    int number[5] = {1,2,3,4,5};
    int *po = &number[0];

    cout << sizeof(po);
#endif

    return a.exec();
}
