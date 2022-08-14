project(HELLO_CONCURRENCY_WORLD)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

add_executable(HELLO_CONCURRENCY_WORLD hello.cpp)
