#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

static inline int add(int x, int y) { return x + y; }

BOOST_AUTO_TEST_SUITE(MyFirstBoostTest)
BOOST_AUTO_TEST_CASE(my_test) {
  BOOST_CHECK(2 == 2);
  BOOST_CHECK(2 != 3);
  // seven ways to detect and report the same error:
  BOOST_CHECK(add(2, 2) == 4);  // #1 continues on error

  BOOST_REQUIRE(add(2, 2) == 4);  // #2 throws on error

  if (add(2, 2) != 4) BOOST_ERROR("Ouch...");  // #3 continues on error

  if (add(2, 2) != 4) BOOST_FAIL("Ouch...");  // #4 throws on error

  if (add(2, 2) != 4) throw "Ouch...";  // #5 throws on error

  BOOST_CHECK_MESSAGE(add(2, 2) == 4,  // #6 continues on error
                      "add(..) result: " << add(2, 2));

  BOOST_CHECK_EQUAL(add(2, 2), 4);  // #7 continues on error
}

BOOST_AUTO_TEST_SUITE_END()

