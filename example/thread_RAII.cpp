/**
 * @Description 手动实现RAII管理mutex资源 锁自动释放
 * @Version 1.0.0
 * @Date 2024/10/9 19:44
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <shared_mutex>

using namespace std;

class XMutex{
public:
    XMutex(mutex &mux):mux_(mux){
        cout << "Lock" << endl;
        mux.lock();
    }

    ~XMutex(){
        cout << "Unlock" << endl;
        mux_.unlock();
    }

private:
    mutex &mux_;
};

static mutex mux;

void TestMutex(int status){
    XMutex lock(mux);

    if (status == 1){
        cout << " =1" << endl;
        return;
    } else{
        cout << " !=1" << endl;
        return;
    }
}

int main(int argc,char *argv[]){
    TestMutex(1);
    TestMutex(2);
    getchar();
}