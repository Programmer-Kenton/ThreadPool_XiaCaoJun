/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:32
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */


#include "threadPool.h"

using namespace std;

int main(int argc,char *argv[]){
    threadPool pool;

    pool.Init(6);

    pool.Start();

//    MyTask task1;
//
//    task1.name = "test name 001";

    auto task3 = make_shared<MyTask>();
    task3->name = "test shared 003";
    pool.AddTask(task3);

//    MyTask task2;
//
//    task2.name = "test name 002";

    auto task4 = make_shared<MyTask>();
    task4->name = "test shared 004";
    pool.AddTask(task4);

    this_thread::sleep_for(100ms);

    cout << "结束之前 task run count = " << pool.task_run_count();

    this_thread::sleep_for(1s);

    pool.Stop();

    cout << "结束之后 task run count = " << pool.task_run_count();

    getchar();
    return 0;
}