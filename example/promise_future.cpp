/**
 * @Description promise和future多线程异步传值
 * @Version 1.0.0
 * @Date 2024/10/10 13:28
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <future>
#include <string>

using namespace std;

void TestFuture(promise<string> p){
    cout << "开始 TestFuture" << endl;
    this_thread::sleep_for(1s);
    cout << "开始设置value" << endl;
    p.set_value("TestFuture value");
    this_thread::sleep_for(1s);
    cout << "结束 TestFuture" << endl;
}


int main(int argc,char *argv[]){
    // 异步传输变量存储
    promise<string> p;

    // 用来获取线程异步值获取
    auto future = p.get_future();

    auto th = thread(TestFuture, move(p));

    th.join();

    cout << "future get() = " << future.get() << endl;

    getchar();
}
