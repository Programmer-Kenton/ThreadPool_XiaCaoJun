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

    {
        /**
         * unique_lock的特点
         * 非独占所有权:与lock_guard不同 unique_lock可以在构造时不锁定互斥量 允许显示地决定何时锁定或解锁互斥量
         * 可重入:unique_lock支持可重入的锁定行为 重复加锁
         * 条件变量等待:可以与条件变量一起使用 以便在等待条件变量时保持互斥量的锁定状态
         * 移动语义:支持移动构造和移动赋值 这使得可以将互斥量的所有权从一个std::unique_lock对象转移到另一个对象
         */

        static mutex mux;
        unique_lock<mutex> lock(mux);
        lock.unlock();
        // 临时释放锁
        lock.lock();
    }

    {
        // 已经拥有锁 不锁定 退出解锁
        mux.lock();
        unique_lock<mutex> lock(mux,adopt_lock);
    }

    {
        // 延后加锁 不拥有 退出不解锁
        unique_lock<mutex> lock(mux,defer_lock);
        // 加锁 退出栈区解锁
        lock.lock();
    }

    {
        // mux.lock();
        // 尝试加锁 不阻塞 失败不拥有锁
        unique_lock<mutex> lock(mux,try_to_lock);
        if (lock.owns_lock()){
            cout << "owns_lock" << endl;
        }else{
            cout << "not owns_lock" << endl;
        }
    }

    getchar();
    for (int i = 0; i < 3; ++i) {
        thread th(TestLockGuard,i + 1);
        th.detach();
    }

    getchar();

    TestMutex(1);
    TestMutex(2);
    getchar();
}