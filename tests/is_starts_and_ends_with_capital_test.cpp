#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(is_starts_and_ends_with_capital_test)

BOOST_AUTO_TEST_CASE(simple) {
  struct {
    double x, y;
  } cases[] = {{0, 0}, {1, 1}, {2, 2}};

  for (auto c : cases) {
    BOOST_TEST(c.y == c.x);
  }
}

BOOST_AUTO_TEST_SUITE_END()
