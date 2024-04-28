#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;
namespace utf = boost::unit_test;

extern "C" bool IsStartsAndEndsWithCapital_C(char const* str);

BOOST_AUTO_TEST_SUITE(is_starts_and_ends_with_capital_test)

BOOST_AUTO_TEST_CASE(hello_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital_C("Hello") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("hello") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("H") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("") == false);
}

BOOST_AUTO_TEST_SUITE_END()
