project(ACCUMULATION)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)

add_executable(ACCUMULATION accumulation_test.cpp accumulation.hpp)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
message(${Boost_INCLUDE_DIRS})

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(ACCUMULATION ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

