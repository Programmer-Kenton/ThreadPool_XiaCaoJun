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
        // auto th = new thread(&threadPool::Run, this);
        auto th = make_shared<thread>(&threadPool::Run, this);
        threads_.push_back(th);
    }
}

void threadPool::Run() {
    cout << "开始 threadPool Run" << this_thread::get_id() << endl;

    while (!is_exit_){
        auto task = GetTask();
        if (!task) continue;

        ++task_run_count_;

        try{
            auto ret = task->Run();
            task->SetValue(ret);

        }catch (...){

        }

        --task_run_count_;

    }

    cout << "结束 threadPool Run" << this_thread::get_id() << endl;
}

void threadPool::AddTask(std::shared_ptr<Task> task) {
    unique_lock<mutex> lock(mtx);

    tasks_.push_back(task);

    task->is_exit = [this]{
        return is_exit_;
    };
}

std::shared_ptr<Task> threadPool::GetTask() {
    unique_lock<mutex> lock(mtx);

    if (tasks_.empty()){
        cv.wait(lock);
    }

    // 如果线程被唤醒且被标记为退出状态则直接返回空
    if (is_exit_) return nullptr;

    // notify_all一起唤醒其他线程消费任务 当前线程被唤醒可能没有任务 因此需要再判断任务是否为空
    if (tasks_.empty()) return nullptr;

    auto task = tasks_.front();
    tasks_.pop_front();
    return task;
}

bool threadPool::is_exit() {
    return is_exit_;
}

void threadPool::Stop() {
    is_exit_ = true;

    cv.notify_all();

    // 等待线程运行结束
    for(auto &th : threads_){
        th->join();
    }

    unique_lock<mutex> lock(mtx);
    threads_.clear();
}

int threadPool::task_run_count() {
    return task_run_count_;
}

threadPool::~threadPool() {
    Stop();
}


