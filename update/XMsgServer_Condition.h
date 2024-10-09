/**
 * @Description 消息服务器
 * @Version 1.0.0
 * @Date 2024/10/9 21:47
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef THREADPOOL_XIACAOJUN_XMSGSERVER_H
#define THREADPOOL_XIACAOJUN_XMSGSERVER_H

#include <string>
#include <list>
#include <mutex>
#include <iostream>
#include <condition_variable>
#include "XThread_Condition.h"

class XMsgServer_Condition : public XThread_Condition{
public:
    // 给当前线程发送消息
    void SendMsg(std::string msg);

    void Stop() override;

private:
    // 处理消息的线程函数入口
    void Main() override;

    // 消息队列缓冲
    std::list<std::string> msgs_;

    // 互斥访问消息队列
    std::mutex mux_;

    std::condition_variable cv;
};


#endif //THREADPOOL_XIACAOJUN_XMSGSERVER_H
