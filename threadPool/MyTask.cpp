/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:54
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#include "MyTask.h"

using namespace std;

int MyTask::Run() {
    cout << "========================多态实现MyTask的Run========================" << endl;
    cout << this_thread::get_id() << " MyTask" << name << endl;
    cout << "========================Run函数允许结束============================" << endl;
}
