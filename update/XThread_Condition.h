/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/9 21:42
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef THREADPOOL_XIACAOJUN_XTHREAD_H
#define THREADPOOL_XIACAOJUN_XTHREAD_H


#include <thread>

class XThread_Condition {
public:

    // 启动线程
    virtual void Start();

    // 设置线程退出标志并等待
    virtual void Stop();

    // 等待线程退出
    virtual void Wait();

    // 线程是否退出
    bool is_exit();

protected:
    bool is_exit_ = false;

private:
    // 线程入口函数
    virtual void Main() = 0;



    std::thread th_;
};


#endif //THREADPOOL_XIACAOJUN_XTHREAD_H
