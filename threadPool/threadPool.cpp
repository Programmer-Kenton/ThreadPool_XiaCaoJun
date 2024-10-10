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
    cout << "开始 threadPool Run" << this_thread::get_id() << endl;

    while (true){
        auto task = GetTask();
        if (!task) continue;

        try{
            task->Run();
        }catch (...){

        }

    }

    cout << "结束 threadPool Run" << this_thread::get_id() << endl;
}

void threadPool::AddTask(Task *task) {
    unique_lock<mutex> lock(mtx);

    tasks_.push_back(task);

    lock.unlock();
    cv.notify_one();
}

Task *threadPool::GetTask() {
    unique_lock<mutex> lock(mtx);

    if (tasks_.empty()){
        cv.wait(lock);
    }

    // notify_all一起唤醒其他线程消费任务 当前线程被唤醒可能没有任务 因此需要再判断任务是否为空
    if (tasks_.empty()) return nullptr;

    auto task = tasks_.front();
    tasks_.pop_front();
    return task;
}
