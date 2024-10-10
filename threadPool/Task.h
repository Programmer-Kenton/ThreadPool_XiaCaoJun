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
#include <future>

class Task {

public:
    virtual int Run() = 0;

    std::function<bool()> is_exit = nullptr;

    void SetValue(int value){
        promise.set_value(value);
    }

    auto GetReturn(){
        // 阻塞等待 set_value
        return promise.get_future().get();
    }

private:
    // 接收返回值
    std::promise<int> promise;
};


#endif //THREADPOOL_XIACAOJUN_TASK_H
