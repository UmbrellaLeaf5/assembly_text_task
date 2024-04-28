#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

namespace tt = boost::test_tools;
namespace utf = boost::unit_test;

extern "C" __attribute__((sysv_abi)) bool IsStartsAndEndsWithCapital(
    char const* str);

BOOST_AUTO_TEST_SUITE(IsStartsAndEndsWithCapital_C_test)

BOOST_AUTO_TEST_CASE(Simple_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital("ABCD") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital("X") == true);

  BOOST_TEST(IsStartsAndEndsWithCapital("abcd") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("x") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("Abc") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("abcX") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("hello") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("Hello") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("hellO") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("HellO") == true);
}

BOOST_AUTO_TEST_CASE(Long_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital("longstringwitjgoewkpfwgld;"
                                        "wkopmlwqmkewngjrejfiedosnebkgrfemdsd"
                                        "ijfnghgfkdfjghfdkhsmallletters") ==
             false);
  BOOST_TEST(IsStartsAndEndsWithCapital(
                 "LongStringjitrhoegkwflmklgerujofidsfkmd;"
                 "liokslmkegrnjkdfkmerdngruijfkdlWithCapitalLetters") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital(
                 "longStringjitrhoegkwflmklgerujofidsfkmd;"
                 "liokslmkegrnjkdfkmerdngruijfkdlWithCapitalLetterS") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("Longstringwitjgoewkpfwgld;"
                                        "wkopmlwqmkewngjrejfiedosnebkgrfemdsd"
                                        "ijfnghgfkdfjghfdkhsmallletterS") ==
             true);
}

BOOST_AUTO_TEST_CASE(Numbers_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital("Hello123") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("Hello123X") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital("123") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("A123B") == true);
}

BOOST_AUTO_TEST_CASE(EmptyStr_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital("") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital(" ") == false);
}

BOOST_AUTO_TEST_CASE(Extra_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital(" AB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("AB ") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital(" A B ") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("A!B") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital("!AB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("A!B!") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("Z ! @ # $ % ^Y") == true);

  BOOST_TEST(IsStartsAndEndsWithCapital("@ ! Z # $ % ^Y") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("# ! Z @ $ % ^Y") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("$ ! Z @ # % ^Y") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("% ! Z @ # $ ^Y") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("@ ! Z # $ % ^Y @") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("# ! Z @ $ % ^Y #") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("$ ! Z @ # % ^Y $") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("% ! Z @ # $ ^Y %") == false);
}

BOOST_AUTO_TEST_CASE(Special_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital("A\nB") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital("\nAB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("A\nB\n") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("A\tB") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital("\tAB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("A\tB\t") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("A\rB") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital("\rAB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital("A\rB\r") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital("A\nB\nC") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital("X\t\tY") == true);
}

BOOST_AUTO_TEST_SUITE_END()
