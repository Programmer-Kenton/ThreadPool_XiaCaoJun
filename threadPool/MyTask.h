/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef THREADPOOL_XIACAOJUN_MYTASK_H
#define THREADPOOL_XIACAOJUN_MYTASK_H

#include "Task.h"
#include <iostream>


class MyTask : public Task{
public:
    int Run();

    std::string name = "";
};


#endif //THREADPOOL_XIACAOJUN_MYTASK_H
