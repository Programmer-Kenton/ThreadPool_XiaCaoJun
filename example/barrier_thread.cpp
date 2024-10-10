/**
 * @Description C++20 屏障barrier实现线程协调
 * @Version 1.0.0
 * @Date 2024/10/10 21:18
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <barrier>

using namespace std;


void TestBar(int i,barrier<> *bar){
    this_thread::sleep_for(chrono::seconds(i));
    cout << i << " begin wait" << endl;
    bar->wait(bar->arrive()); // 期待数-1 阻塞等待 期待为0是返回
    cout << i << " end wait" << endl;
}

int main(int argc,char *argv[]){
    int count = 3;

    // 初始数量
    barrier bar(count);

    for (int i = 0; i < count; ++i) {
        thread th(TestBar,i,&bar);
        th.detach();
    }
    getchar();
}