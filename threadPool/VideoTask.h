/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 20:30
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#ifndef THREADPOOL_XIACAOJUN_VIDEOTASK_H
#define THREADPOOL_XIACAOJUN_VIDEOTASK_H

#include "Task.h"

class VideoTask : public Task{

public:
    std::string in_path;

    std::string out_path;

    int width = 0;

    int height = 0;

private:
    int Run();
};


#endif //THREADPOOL_XIACAOJUN_VIDEOTASK_H
