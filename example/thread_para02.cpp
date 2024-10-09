/**
 * @Description 使用成员函数作为线程入口并封装线程基类接口
 * @Version 1.0.0
 * @Date 2024/10/9 15:47
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <iostream>
#include <thread>
using namespace std;

class MyThread{
public:

    // 入口线程函数
    void Main(){
        cout << "MyThread Main" << name << ":" << age;
    }
    string name = "";
    int age = 100;
};


class XThread{

public:
    virtual void Start(){
        is_exit_ = false;
        th_ = std::thread(&XThread::Main, this);
    }

    virtual void Wait(){
        if (th_.joinable()){
            th_.join();
        }
    }

    virtual void Stop(){
        is_exit_ = true;
        Wait();
    }

    bool is_exit(){
        return is_exit_;
    }

private:
    virtual void Main() = 0;
    std::thread th_;
    bool is_exit_ = false;
};

class TestXThread : public XThread{
public:
    void Main() override{
        cout << "TestXThread Main 开始" << endl;
        while (!is_exit()){
            this_thread::sleep_for(100ms);
            cout << '.' << flush;
        }
        cout << endl;
        cout << "TestXThread Main 结束" << endl;
    }

    string name;
};

int main(int arc,char *argv[]){
//    MyThread myth;
//
//    myth.name = "Test name 001";
//    myth.age = 20;
//
//    thread th(&MyThread::Main,&myth);
//
//    th.join();

    TestXThread testth;
    testth.name = "TestXThread name";
    testth.Start();
    this_thread::sleep_for(3s);
    testth.Stop();

    testth.Wait();
    getchar();
}