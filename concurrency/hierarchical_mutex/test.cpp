#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <thread>
#include "test_func.h"

BOOST_AUTO_TEST_SUITE(ACCUMULATION_Test)
BOOST_AUTO_TEST_CASE(test_functions) {
  std::vector<std::vector<int>> a = {{1, 0}, {0, 1}};
  std::vector<std::thread> threads(20);
  for (int i = 0; i < 10; ++i) {
    threads[2 * i + 1] = std::thread(high_level);
    threads[2 * i] = std::thread(low_level);
  }
  for (auto& thr : threads) thr.join();
  BOOST_CHECK(high_level_count == 10);
  BOOST_CHECK(low_level_count == 20);
}
BOOST_AUTO_TEST_SUITE_END()
