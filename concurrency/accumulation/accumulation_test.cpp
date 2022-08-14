#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include "accumulation.hpp"
#include <boost/test/unit_test.hpp>
#include <thread>

BOOST_AUTO_TEST_SUITE(ACCUMULATION_Test)
BOOST_AUTO_TEST_CASE(test_vector_of_int) {
  std::vector<int> v1(100000);
  int result = 0;
  parallel_accumulate(v1.begin(), v1.end(), result);
  BOOST_CHECK(result == 0);
}

BOOST_AUTO_TEST_CASE(test_2_vector_of_int) {
  std::vector<int> v2(100);
  int i = 1;
  for (auto& el : v2) {
    el = i++;
  }
  int result = 0;
  parallel_accumulate(v2.begin(), v2.end(), result);
  BOOST_CHECK(result == 5050);
}

BOOST_AUTO_TEST_SUITE_END()
