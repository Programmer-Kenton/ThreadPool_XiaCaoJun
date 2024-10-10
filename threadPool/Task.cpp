/**
 * @Description TODO
 * @Version 1.0.0
 * @Date 2024/10/10 17:50
 * @Github https://github.com/Programmer-Kenton
 * @Author Kenton
 */
#include "Task.h"

auto Task::GetReturn() {
    // 阻塞等待 set_value
    return promise.get_future().get();
}

void Task::SetValue(int value) {
    promise.set_value(value);
}
