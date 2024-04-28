#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;
namespace utf = boost::unit_test;

extern "C" __attribute__((sysv_abi)) char FirstOf(char const* str);
extern "C" __attribute__((sysv_abi)) char LastOf(char const* str);

BOOST_AUTO_TEST_SUITE(IsStartsAndEndsWithCapital_C_test)

BOOST_AUTO_TEST_CASE(Simple_test) {
  BOOST_TEST(FirstOf("ABCD") == 'A');
  BOOST_TEST(FirstOf("X") == 'X');

  BOOST_TEST(LastOf("ABCD") == 'D');
  BOOST_TEST(LastOf("X") == 'X');
}

BOOST_AUTO_TEST_SUITE_END()
