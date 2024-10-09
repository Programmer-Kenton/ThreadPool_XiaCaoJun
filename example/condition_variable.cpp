/**
 * @Description condition_variable读写线程同步
 * @Version 1.0.0
 * @Date 2024/10/9 22:16
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <mutex>
#include <list>
#include <string>
#include <sstream>
#include <condition_variable>

using namespace std;

list<string> msgs_;

mutex mux;

condition_variable cv;

void ThreadWrite(){
    for(int i = 0;;i++){
        stringstream ss;
        unique_lock<mutex> lock(mux);
        ss << "Write msg " << i;
        msgs_.push_back(ss.str());
        lock.unlock();
        cv.notify_one(); // 发送信号
        this_thread::sleep_for(3s);
    }
}

void ThreadRead(int i){
    for(;;){
        cout << "read msg..." << endl;
        // 加锁
        unique_lock<mutex> lock(mux);
        // cv.wait(lock); // 收到信号 解锁、阻塞等待信号
        cv.wait(lock,[i]{
            cout << i << " wait" << endl;
            return !msgs_.empty();
        });
        // 获得信号后锁定
        while (!msgs_.empty()){
            cout << i << " read " << msgs_.front() << endl;
            msgs_.pop_front();
        }
        if (msgs_.empty()) return;

    }
}

int main(int argc,char *argv[]){
    thread th(ThreadWrite);
    th.detach();

    for (int i = 0; i < 3; ++i) {
        thread th(ThreadRead,i + 1);
        th.detach();
    }

    getchar();
}