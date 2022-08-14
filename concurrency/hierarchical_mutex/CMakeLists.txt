project(hierarchical_mutex)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

add_executable(hierarchical_mutex test.cpp hierarchical_mutex.h test_func.h)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
message(${Boost_INCLUDE_DIRS})

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(hierarchical_mutex ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
