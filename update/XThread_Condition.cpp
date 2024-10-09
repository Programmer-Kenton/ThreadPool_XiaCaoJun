/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/9 21:42
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "XThread_Condition.h"

void XThread_Condition::Start() {
    is_exit_ = false;
    th_ = std::thread(&XThread_Condition::Main,this);
}

void XThread_Condition::Wait() {
    if (th_.joinable()){
        th_.join();
    }
}

void XThread_Condition::Stop() {
    is_exit_ = true;
    // 等待线程退出 并不是立即退出
    Wait();
}

bool XThread_Condition::is_exit() {
    return is_exit_;
}

