/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:32
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */


#include "threadPool.h"

int main(int argc,char *argv[]){
    threadPool pool;

    pool.Init(6);

    pool.Start();

    MyTask task1;

    task1.name = "test name 001";

    pool.AddTask(&task1);

    getchar();
    return 0;
}