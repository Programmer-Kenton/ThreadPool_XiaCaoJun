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

static mutex gmutex;
void TestLockGuard(int i){

    gmutex.lock();
    {
        // adopt_lock的用途
        // 当已经有一个锁定互斥量的上下文 并且想要在该上下文中使用std::lock_guard来管理这个互斥量的生命周期时
        // 这种情况 不希望lock_guard再次锁定互斥量 而是希望它接管现有的锁定状态并在std::lock_guard对象的生命周期结束的时候自动释放锁
        lock_guard<mutex> lock(gmutex,adopt_lock);
    }

    {
        lock_guard<mutex> lock(gmutex);
        cout << "begin thread " << i << endl;
    }

    for(;;){
        {
            lock_guard<mutex> lock(gmutex);
            cout << "In " << i << endl;
        }
        this_thread::sleep_for(500ms);
    }
}

int main(int argc,char *argv[]){

    for (int i = 0; i < 3; ++i) {
        thread th(TestLockGuard,i + 1);
        th.detach();
    }

    getchar();

    TestMutex(1);
    TestMutex(2);
    getchar();
}