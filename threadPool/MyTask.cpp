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


    for (int i = 0; i < 10; ++i) {
        if (is_exit()) break;
        cout << '.' << flush;
        this_thread::sleep_for(500ms);
    }
    cout << endl;
    cout << "========================MyTask的Run函数运行结束============================" << endl;
    return 100;
}
