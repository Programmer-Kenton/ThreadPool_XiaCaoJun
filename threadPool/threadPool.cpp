/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:30
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#include "threadPool.h"

using namespace std;

void threadPool::Init(int num) {
    unique_lock<mutex> lock(mtx);

    this->thread_num = num;
    cout << "Thread Pool Init" << num << endl;
}

void threadPool::Start() {
    unique_lock<mutex> lock(mtx);

    if (thread_num <= 0){
        cerr << "Please Init threadPool..." << endl;
        return;
    }

    if (!threads_.empty()){
        cerr << "Thread Pool has start..." << endl;
        return;
    }

    // 启动线程
    for (int i = 0; i < thread_num; ++i) {
        auto th = new thread(&threadPool::Run, this);
        threads_.push_back(th);
    }
}

void threadPool::Run() {
    cout << "begin threadPool Run" << this_thread::get_id() << endl;
    cout << "end threadPool Run" << this_thread::get_id() << endl;
}
