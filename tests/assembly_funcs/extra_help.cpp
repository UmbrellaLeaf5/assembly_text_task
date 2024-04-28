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

BOOST_AUTO_TEST_CASE(EmptyStr_test) {
  BOOST_TEST(FirstOf("") == '\0');
  BOOST_TEST(FirstOf(" ") == ' ');
  BOOST_TEST(FirstOf(nullptr) == '\0');

  BOOST_TEST(LastOf("") == '\0');
  BOOST_TEST(LastOf(" ") == ' ');
  BOOST_TEST(LastOf(nullptr) == '\0');
}

BOOST_AUTO_TEST_CASE(Long_test) {
  std::string long_string(1000, 'X');

  BOOST_TEST(FirstOf(long_string.c_str()) == 'X');
  BOOST_TEST(LastOf(long_string.c_str()) == 'X');

  // вставка спец. символов в начало строки
  long_string.insert(0, 1, '\t');
  long_string.insert(1, 1, '\n');
  long_string.insert(2, 1, '\r');

  BOOST_TEST(FirstOf(long_string.c_str()) == '\t');

  // вставка спец. символов в конец строки
  long_string.append(1, '\t');
  long_string.append(1, '\n');
  long_string.append(1, '\r');

  BOOST_TEST(LastOf(long_string.c_str()) == '\r');
}

BOOST_AUTO_TEST_CASE(Special_test) {
  BOOST_TEST(FirstOf("\n\t\r") == '\n');
  BOOST_TEST(FirstOf("\0ABC") == '\0');
  BOOST_TEST(FirstOf("\t\n\r") == '\t');
  BOOST_TEST(FirstOf("\x01\x02\x03") == '\x01');

  BOOST_TEST(LastOf("\n\t\r") == '\r');
  BOOST_TEST(LastOf("ABC\0") == 'C');
  BOOST_TEST(LastOf("\t\n\r") == '\r');
  BOOST_TEST(LastOf("\x01\x02\x03") == '\x03');
}

BOOST_AUTO_TEST_SUITE_END()
