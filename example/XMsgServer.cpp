/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/9 21:47
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "XMsgServer.h"

using namespace std;
using namespace this_thread;

void XMsgServer::SendMsg(std::string msg) {

    // 向List进行写操作前加锁
    std::unique_lock<std::mutex> lock(mux_);
    msgs_.push_back(msg);
}

void XMsgServer::Main() {
    while (!is_exit()){
        // 加锁前睡眠
        sleep_for(10ms);
        // 加锁后判断list容器是否为空
        std::unique_lock<std::mutex> lock(mux_);
        if (msgs_.empty()){
            continue;
        }

        while (!msgs_.empty()){
            cout << "接收到消息... " << msgs_.front() << endl;
            // 把读取的消息从list中销毁
            msgs_.pop_front();
        }
    }
}
