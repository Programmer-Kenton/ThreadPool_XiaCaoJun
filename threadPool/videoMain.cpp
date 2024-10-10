/**
 * @Description 基于线程池实现音视频批量转码测试
 * @Version 1.0.0
 * @Date 2024/10/10 20:03
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "threadPool.h"
#include "VideoTask.h"
#include <iostream>


using namespace std;

/**
 * 命令行视频转码工具
 * ffmpeg工具 用户输入视频源 输出视频尺寸
 * 在线程池中执行转码任务
 * 转码任务调用ffmpeg
 * @param argc
 * @param argv
 * @return
 */
int main(int argc,char *argv[]){
    threadPool pool;

    pool.Init(16);

    pool.Start();

    auto task1 = make_shared<VideoTask>();

    task1->in_path = "test.mp4";
    task1->out_path = "640.mp4";

    task1->width = 640;
    task1->height = 480;
    pool.AddTask(task1);

    task1->GetReturn();

}