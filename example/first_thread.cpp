/**
 * @Description thread对象生命周期和线程等待分离
 * @Version 1.0.0
 * @Date 2024/10/9 14:38
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>


using namespace std;

bool is_exit = false;

void ThreadMain(){
    cout << "子线程 begin sub thread ID" << this_thread::get_id() << endl;

    for (int i = 0; i < 10; ++i) {
        if (!is_exit) break;
        cout << "in thread" << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "子线程 end sub thread ID" << this_thread::get_id() << endl;
}

int main(int argc,char *argv[]){

//    cout << "主线程 main thread ID " << this_thread::get_id() << endl;
//
//    // 线程创建启动
//    thread th(ThreadMain);
//
//    cout << "等待子线程 wait sub thread" << endl;
//    // 阻塞等待子线程退出
//    th.join();
//
//    cout << "等待子线程结束..." << endl;

//    {
//        thread th(ThreadMain); // 出错 thread对象被销毁 但子线程还在运行
//    }

//    {
//        thread th(ThreadMain);
//        // 等待子线程退出
//        th.join(); // 主线程阻塞 等待子线程退出
//    }

//    {
//        thread th(ThreadMain);
//        th.detach(); // 子线程与主线程分离 守护线程
//        // 坑 主线程退出后 子线程不一定会退出
//    }

    {
        thread th(ThreadMain);
        this_thread::sleep_for(chrono::seconds(1));
        is_exit = true; // 通知子线程退出
        cout << "主线程阻塞 等待子线程退出" << endl;
        th.join(); // 主线程阻塞等待子线程退出
        cout << "子线程已经退出..." << endl;
    }
    return 0;
}

