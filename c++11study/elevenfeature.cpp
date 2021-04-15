#include "elevenfeature.h"
#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <QDebug>
using namespace std::placeholders;

//普通函数
void thread_function() {
    for (int i = 0; i < 5; i++)
        std::cout << "chirld thread function excuting" << std::endl;
}

//测试条件变量的
class Application {
    std::mutex m_mutex;
    std::condition_variable m_condVar;
    bool m_bDataLoaded;
public:
    Application() {
        m_bDataLoaded = false;
        std::cout << "4444222222225555" << std::endl;

        std::cout << "555555555555555555555" << std::endl;
    }

    void loadData() {

        std::cout << "fffffffffffffffffffff" << std::endl;
        //使该线程sleep 1秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "condition_variable Loading Data start notify!!" << std::endl;

        //锁定数据
        std::lock_guard<std::mutex> guard(m_mutex);

        //flag设为true，表明数据已加载
        m_bDataLoaded = true;

        //通知条件变量
        m_condVar.notify_one();
    }

    bool isDataLoaded() {
        return m_bDataLoaded;
    }

    void mainTask() {
        std::cout << "Do some handshaking" << std::endl;

        //获取锁
        std::unique_lock<std::mutex> mlock(m_mutex);

        //开始等待条件变量得到信号
        //wait()将在内部释放锁，并使线程阻塞
        //一旦条件变量发出信号，则恢复线程并再次获取锁
        //然后检测条件是否满足，如果条件满足，则继续，否则再次进入wait
        //bind函数第二个参数this，是实际对象
        m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
        std::cout << "condition_variable  Do Processing On loaded Data finished!!" << std::endl;
    }
};


ElevenFeature::ElevenFeature()
{

}


void ElevenFeature::commonFunction()
{
    std::thread threadObj(thread_function);
    for (int i = 0; i < 5; i++)
        std::cout << "Display from MainThread" << std::endl;
    //threadObj.detach();
    threadObj.join();
    std::cout << "Exit of commonFunction of Multithreading" << std::endl;
}

void ElevenFeature::conditionFunction()
{
    Application app;
    std::thread thread_1(&Application::mainTask, &app);
    std::thread thread_2(&Application::loadData, &app);
    thread_2.join();
    thread_1.join();
}

void ElevenFeature::test()
{

}

void ElevenFeature::test1()
{

}
