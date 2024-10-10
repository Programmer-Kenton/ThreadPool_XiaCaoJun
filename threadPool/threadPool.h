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

class threadPool {

public:
    // 初始化线程池
    void Init(int num);

    // 启动所有线程池 必须先调用Init
    void Start();

private:
    // 线程池的入口函数
    void Run();

    // 线程数量
    int thread_num = 0;

    std::mutex mtx;

    std::vector<std::thread*> threads_;
};


#endif //THREADPOOL_XIACAOJUN_THREADPOOL_H
