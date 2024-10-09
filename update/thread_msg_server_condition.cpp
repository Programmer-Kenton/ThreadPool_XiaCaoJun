/**
 * @Description 使用互斥锁和list实现线程通信
 * @Version 1.0.0
 * @Date 2024/10/9 21:36
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <iostream>
#include <sstream>
#include "XMsgServer_Condition.h"

using namespace std;

int main(int argc,char *argv[]){

    XMsgServer_Condition server;

    server.Start();

    for (int i = 0; i < 10; ++i) {
        stringstream ss;
        ss << " msg : " << i + 1;
        server.SendMsg(ss.str());
        this_thread::sleep_for(500ms);
    }

    server.Stop();
    cout << "Server stopped..." << endl;
}