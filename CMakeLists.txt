cmake_minimum_required(VERSION 3.30)
project(ThreadPool_XiaCaoJun)

set(CMAKE_CXX_STANDARD 20)

add_executable(first_thread example/first_thread.cpp)
add_executable(thread_para example/thread_para.cpp)
add_executable(thread_para02 example/thread_para02.cpp)
add_executable(thread_lambda example/thread_lambda.cpp)
add_executable(thread_mutex example/thread_mutex.cpp)
add_executable(thread_shared example/thread_shared.cpp)
add_executable(thread_RAII example/thread_RAII.cpp)
add_executable(thread_msg_server example/thread_msg_server.cpp example/XThread.h example/XThread.cpp example/XMsgServer.h example/XMsgServer.cpp)
add_executable(condition_variable example/condition_variable.cpp)


add_executable(
        server_condition
        update/thread_msg_server_condition.cpp
        update/XMsgServer_Condition.h
        update/XMsgServer_Condition.cpp
        update/XThread_Condition.cpp
        update/XThread_Condition.h
)


add_executable(promise_future example/promise_future.cpp)
add_executable(package_task example/package_task.cpp)
add_executable(async_thread example/async_thread.cpp)
add_executable(base_thread example/base16_thread.cpp)

add_executable(threadPool threadPool/main.cpp threadPool/threadPool.h threadPool/threadPool.cpp)