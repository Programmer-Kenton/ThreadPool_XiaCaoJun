/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:50
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef THREADPOOL_XIACAOJUN_TASK_H
#define THREADPOOL_XIACAOJUN_TASK_H

#include <thread>
#include <mutex>
#include <vector>
#include <functional>

class Task {

public:
    virtual int Run() = 0;

    std::function<bool()> is_exit = nullptr;
};


#endif //THREADPOOL_XIACAOJUN_TASK_H
