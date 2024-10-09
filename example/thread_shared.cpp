/**
 * @Description 共享锁shared_mutex解决读写问题
 * @Version 1.0.0
 * @Date 2024/10/9 19:28
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <shared_mutex>

using namespace std;

shared_timed_mutex stmux;

void ThreadRead(int i){
    for(;;){
        // 共享随允许多个读线程并发执行 一旦有写操作 任何读线程都得等待
        stmux.lock_shared();
        cout << i << " Read" << endl;
        this_thread::sleep_for(500ms);
        stmux.unlock_shared();
        this_thread::sleep_for(1ms);
    }
}

void ThreadWrite(int i){
    for(;;){
        stmux.lock_shared();
        // 读取数据
        stmux.unlock_shared();
        stmux.lock(); // 互斥锁 写入
        cout << i << " Write" << endl;
        this_thread::sleep_for(300ms);
        stmux.unlock();
        this_thread::sleep_for(1ms);
    }
}

int main(int argc,char *argv[]){
    for (int i = 0; i < 3; ++i) {
        thread th(ThreadWrite,i + 1);
        th.detach();
    }

    for (int i = 0; i < 3; ++i) {
        thread th(ThreadRead,i + 1);
        th.detach();
    }

    getchar();
}