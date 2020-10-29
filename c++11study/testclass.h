#ifndef TESTCLASS_H
#define TESTCLASS_H
#include <QDebug>
#include <iostream>
#include <memory>

using namespace std;

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


class KeywordClass{
public:
    KeywordClass() = default;
//    {
//        cout << "KeywordClass base class " << endl;
//    }

    KeywordClass(int value)
    {
        cout << "KeywordClass base class have  Type reference" << endl;
    }

    virtual void test()
    {
        cout << "KeywordClass base test function!"<<endl;
    }

    //禁用拷贝构造，相当于放在了private那种写法。
    KeywordClass(const KeywordClass &value) = delete;
//    {
//         cout << "KeywordClass copy function!"<<endl;
//    }

    void func()
    {
        cout << "in Base::func()" << endl;
    }

    void func(int n)
    {
        cout << "in Base::func(int)" << endl;
    }

};


class DriveKeywordClass : public KeywordClass
{
public:
    DriveKeywordClass() {
        cout << "DriveKeywordClass base class " << endl;
    }

    void test() override;

    using KeywordClass::func;	//引入父类所有同名函数func，解除函数隐藏
    void func()
    {
        cout<<"in Sub::func()" << endl;
    }

    void constfunc() const
    {
        cout<<"this is DriveKeywordClass const func!!" << endl;
    }

    void lambdafunc()
    {
        int a = 1;
        int b = 2;
        int c = 3;
        auto f = [&,a]{
            cout << "lambdafunc a = " << a << " b=" << b << " c="  << c << endl;
        };

        a++;
        b++;
        c++;
        f();
    }


    void  SmartPointer()
    {
        string *s1 = new string("s1");

        shared_ptr<string> ps1(s1);
        cout << ps1.use_count()<<endl;	//1

        shared_ptr<string> ps2;
        ps2 = ps1;

        cout << ps1.use_count()<<endl;	//2
        cout<<ps2.use_count()<<endl;	//2
        cout << ps1.unique()<<endl;	//0

        string *s3 = new string("s3");
        shared_ptr<string> ps3(s3);

        cout << (ps1.get()) << endl;	//033AEB48
        cout << ps3.get() << endl;	//033B2C50
        swap(ps1, ps3);	//交换所拥有的对象
        cout << (ps1.get())<<endl;	//033B2C50
        cout << ps3.get() << endl;	//033AEB48
        cout << ps2.get() << endl;	//033AEB48

        cout << ps1.use_count()<<endl;	//1
        cout << ps2.use_count() << endl;	//2
        ps2 = ps1;
        cout << ps1.use_count()<<endl;	//2
        cout << ps2.use_count() << endl;	//2
        ps1.reset();	//放弃ps1的拥有权，引用计数的减少
        cout << ps1.use_count()<<endl;	//0
        cout << ps2.use_count()<<endl;	//1
        cout << *ps2<<endl;	//s3
    }


};


#endif // TESTCLASS_H
