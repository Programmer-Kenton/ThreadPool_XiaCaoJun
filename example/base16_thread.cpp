/**
 * @Description C++多核计算分析并实现base16编码
 * @Version 1.0.0
 * @Date 2024/10/10 14:32
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

static const char base16[] = "0123456789abcdef";

void Base16Encode(const unsigned char *data,int size,unsigned char *out){
    for (int i = 0; i < size; ++i) {
        unsigned char d = data[i];
        // 0000 0000
        // 1234 5678
        char a = base16[d >> 4];
        char b = base16[d & 0x0F];
        out[i*2] = a;
        out[i*2+1] = b;

    }
}

int main(int argc,char *argv[]){
    string test_data = "测试base16编码";
    unsigned char out[1024] = {0};
    Base16Encode((unsigned char*)test_data.data(),test_data.size(),out);
    cout << "base16:" << out << endl;

    // 测试单线程base16编码效率
    {
        // 初始化测试数据
        vector<unsigned char> in_data;
        in_data.resize(1024 * 1024 * 100);
        for (int i = 0; i < in_data.size(); ++i) {
            in_data[i] = i % 256;
        }

        vector<unsigned char> out_data;
        out_data.resize(in_data.size() * 2);
        auto start = system_clock::now();
        Base16Encode(in_data.data(),in_data.size(),out_data.data());
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        // cout << out_data.data() << endl;
        cout << "编码: " << in_data.size() << " 字节数据花费 " << duration.count() << "ms" << endl;

    }

    getchar();
}