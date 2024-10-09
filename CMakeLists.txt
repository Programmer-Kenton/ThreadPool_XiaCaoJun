cmake_minimum_required(VERSION 3.30)
project(ThreadPool_XiaCaoJun)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp)

add_executable(first_thread example/first_thread.cpp)
add_executable(thread_para example/thread_para.cpp)
add_executable(thread_para02 example/thread_para02.cpp)
add_executable(thread_lambda example/thread_lambda.cpp)
add_executable(thread_mutex example/thread_mutex.cpp)