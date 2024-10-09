/**
 * @Description lambda临时函数作为线程入口
 * @Version 1.0.0
 * @Date 2024/10/9 16:22
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <string>

using namespace std;

class TestLambda{
public:
    void Start(){
        thread th([this] (){cout << "name = " << name  << endl;});
        th.join();
    }

    string name = "test lambda";
};

int main(int argc,char *argv[]){
    thread th([](int i)
    {cout << "test lambda" << i << endl;}
    ,123);

    th.join();
    TestLambda test;

    test.Start();
}