/**
 * @Description 全局函数作为线程入口分析参数传递内存操作&线程函数传递指针和引用
 * @Version 1.0.0
 * @Date 2024/10/9 15:11
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <string>
using namespace std;


class Para{
public:
    Para(){
        cout << "Create Para" << endl;
    }

    ~Para() {
        cout << "Drop Para" << endl;
    }

    Para(const Para &p){
        cout << "Copy Para" << endl;
    }
    string name;
};

void ThreadMain(int p1,float p2,string str,Para p4){
    this_thread::sleep_for(100ms);
    cout << "ThreadMain " << p1 << " " << p2 << " " << str << " " << p4.name << endl;
}

void ThreadMainPtr(Para *p){
    this_thread::sleep_for(100ms);
    cout << "ThreadMainPtr name = " << p->name << endl;
}


void ThreadMainRef(Para &p){
    this_thread::sleep_for(100ms);
    cout << "ThreadMainRef name = " << p.name << endl;
}

int main(int argc,char *argv[]){


    {
        // 传递引用
        Para p;
        p.name = "传递线程引用对象参数";
        thread th(ThreadMainRef, ref(p)); // ref(p)说明是引用
        th.join();
    }

    getchar();

    {
        // 传递线程指针
        Para p;
        p.name = "test ThreadMainPtr name";
        thread th(ThreadMainPtr,&p); // 错误 线程访问的p空间会提前释放
        th.detach();
    }


    // Para释放
    getchar();

    thread th;
    {
        float f1 = 12.1f;

        Para p;
        p.name = "test Para Class";
        // 所有参数做复制
        th = thread(ThreadMain,101,f1,"test string para",p);
        th.join();
    }
}
