/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 20:30
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */

#include "VideoTask.h"
#include <sstream>

using namespace std;

int VideoTask::Run() {
    // ffmpeg -y -i test.mp4 -s 400x300 400.mp4 >log.txt 2>&1
    stringstream ss;
    ss << "ffmpeg -y -i" << in_path << " ";
    if (width > 0 &&  height > 0){
        ss << " -s " << width << "x" << height << " ";
    }
    ss << out_path;
    ss << " >" << this_thread::get_id() << ".txt 2>&1";
    return system(ss.str().c_str());
}
