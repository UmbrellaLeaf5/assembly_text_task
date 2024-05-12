#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>

/**
 * @brief Проверяет свойство текста: текст начинается заглавной латинской буквой
 * и оканчивается заглавной латинской буквой
 * @param str: входной текст
 * @return true: свойство выполняется
 * @return false: свойство не выполняется
 */
extern "C" bool IsStartsAndEndsWithCapital_C(char const* str);

BOOST_AUTO_TEST_SUITE(IsStartsAndEndsWithCapital_C_test)

BOOST_AUTO_TEST_CASE(Simple_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital_C("ABCD") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("X") == true);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("abcd") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("x") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("Abc") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("abcX") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("hello") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("Hello") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("hellO") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("HellO") == true);
}

BOOST_AUTO_TEST_CASE(Long_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital_C("longstringwitjgoewkpfwgld;"
                                          "wkopmlwqmkewngjrejfiedosnebkgrfemdsd"
                                          "ijfnghgfkdfjghfdkhsmallletters") ==
             false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C(
                 "LongStringjitrhoegkwflmklgerujofidsfkmd;"
                 "liokslmkegrnjkdfkmerdngruijfkdlWithCapitalLetters") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C(
                 "longStringjitrhoegkwflmklgerujofidsfkmd;"
                 "liokslmkegrnjkdfkmerdngruijfkdlWithCapitalLetterS") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("Longstringwitjgoewkpfwgld;"
                                          "wkopmlwqmkewngjrejfiedosnebkgrfemdsd"
                                          "ijfnghgfkdfjghfdkhsmallletterS") ==
             true);
}

BOOST_AUTO_TEST_CASE(Numbers_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital_C("Hello123") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("Hello123X") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("123") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("A123B") == true);
}

BOOST_AUTO_TEST_CASE(EmptyStr_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital_C(nullptr) == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C(" ") == false);
}

BOOST_AUTO_TEST_CASE(Extra_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital_C(" AB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("AB ") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C(" A B ") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("A!B") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("!AB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("A!B!") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("Z ! @ # $ % ^Y") == true);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("@ ! Z # $ % ^Y") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("# ! Z @ $ % ^Y") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("$ ! Z @ # % ^Y") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("% ! Z @ # $ ^Y") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("@ ! Z # $ % ^Y @") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("# ! Z @ $ % ^Y #") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("$ ! Z @ # % ^Y $") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("% ! Z @ # $ ^Y %") == false);
}

BOOST_AUTO_TEST_CASE(Special_test) {
  BOOST_TEST(IsStartsAndEndsWithCapital_C("A\nB") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("\nAB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("A\nB\n") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("A\tB") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("\tAB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("A\tB\t") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("A\rB") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("\rAB") == false);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("A\rB\r") == false);

  BOOST_TEST(IsStartsAndEndsWithCapital_C("A\nB\nC") == true);
  BOOST_TEST(IsStartsAndEndsWithCapital_C("X\t\tY") == true);
}

BOOST_AUTO_TEST_SUITE_END()
