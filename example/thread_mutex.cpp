/**
 * @Description 竞争状态和临界区介绍 互斥锁mutex
 * @Version 1.0.0
 * @Date 2024/10/9 18:46
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <string>
#include <mutex>


using namespace std;

static mutex mtx;

void TestThread() {
    // 获取锁资源 如果没有则阻塞等待
//    mtx.lock();
//    cout << "===========================" << endl;
//    cout << "test 001" << endl;
//    cout << "test 002" << endl;
//    cout << "test 003" << endl;
//    cout << "===========================" << endl;
//    // 释放锁资源
//    mtx.unlock();

    for (;;) {
        // 尝试获取锁资源 如果没有则阻塞等待
        if (!mtx.try_lock()) {
            cout << '.' << flush;
            this_thread::sleep_for(100ms);
            continue;
        }

        cout << "===========================" << endl;
        cout << "test 001" << endl;
        cout << "test 002" << endl;
        cout << "test 003" << endl;
        cout << "===========================" << endl;
        // 释放锁资源
        mtx.unlock();
        this_thread::sleep_for(1000ms);
    }
}


void ThreadMainMux(int i){
    for(;;){
        mtx.lock();
        cout << i << "[in]" << endl;
        this_thread::sleep_for(1000ms);
        mtx.unlock();
        // 留一部分时间给操作系统释放锁资源 不然释放后直接去获取 速度太快微秒级的 操作系统还没有真正释放锁
        this_thread::sleep_for(1ms);
    }
}

int main(int argc, char *argv[]) {


    for (int i = 0; i < 3; ++i) {
        thread th(ThreadMainMux,i + 1);
        th.detach();
    }

    getchar();
    for (int i = 0; i < 10; ++i) {
        thread th(TestThread);
        th.detach();
    }

    getchar();
}