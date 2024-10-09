/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/9 21:42
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "XThread.h"

void XThread::Start() {
    is_exit_ = false;
    th_ = std::thread(&XThread::Main,this);
}

void XThread::Wait() {
    if (th_.joinable()){
        th_.join();
    }
}

void XThread::Stop() {
    is_exit_ = true;
    // 等待线程退出 并不是立即退出
    Wait();
}

bool XThread::is_exit() {
    return is_exit_;
}

