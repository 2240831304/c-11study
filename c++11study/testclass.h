#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <QDebug>

class BaseClass
{
public:
    BaseClass(int a)
    {
        qDebug() << "ji lei gouzao";
    }

     ~BaseClass()
    {
        qDebug() << "ji lei xigou";
    }
};


class SubClass : public BaseClass
{
public:
    SubClass()
        :BaseClass(12)
    {
        qDebug() << "zi lei gouzao";
    }

     ~SubClass()
    {
        qDebug() << "zi lei xigou";
    }
};



#endif // TESTCLASS_H
