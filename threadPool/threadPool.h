/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:30
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef THREADPOOL_XIACAOJUN_THREADPOOL_H
#define THREADPOOL_XIACAOJUN_THREADPOOL_H

#include <thread>
#include <mutex>
#include <iostream>
#include <vector>
#include <list>
#include <condition_variable>
#include "MyTask.h"

class threadPool {

public:
    // 初始化线程池
    void Init(int num);

    // 启动所有线程池 必须先调用Init
    void Start();

    // 线程池的退出
    void Stop();

    void AddTask(Task *task);

    Task *GetTask();

    bool is_exit();

private:
    // 线程池的入口函数
    void Run();

    // 线程数量
    int thread_num = 0;

    std::mutex mtx;

    std::vector<std::thread*> threads_;

    std::list<Task*> tasks_;

    std::condition_variable cv;

    // 线程池退出标志
    bool is_exit_ = false;
};


#endif //THREADPOOL_XIACAOJUN_THREADPOOL_H
