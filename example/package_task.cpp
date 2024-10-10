/**
 * @Description package_task异步调用函数打包
 * @Version 1.0.0
 * @Date 2024/10/10 13:50
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <future>
#include <string>

using namespace std;

string TestPack(int index){
    cout << "开始...TestPack函数 " << index << endl;
    this_thread::sleep_for(2s);
    return "Test Pack return";
}


int main(int argc,char *argv[]){
    packaged_task<string(int)> task(TestPack);
    auto result = task.get_future();
    task(100);

    thread th(move(task),101);



    cout << "begin result get" << endl;

    for (int i = 0; i < 10; ++i) {
        if (result.wait_for(100ms) != future_status::ready){
            continue;
        }
    }

    if (result.wait_for(100ms) == future_status::timeout){
        cout << "wait result timeout " << endl;
    } else{
        cout << "result get " << result.get() << endl;
    }


    th.join();

    getchar();
}