#include <boost/test/unit_test.hpp>
#include <cctype>
#include <cstring>

extern "C" void ChangeAllLatinToStar_C(char* str);

BOOST_AUTO_TEST_SUITE(ChangeAllLatinToStar_C_Tests)

BOOST_AUTO_TEST_CASE(Simple_test) {
  char str[] = "HelloWorld";
  const char expected[] = "**********";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(EmptyStr_test) {
  char str[] = "";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strlen(str) == 0);

  char* str_2 = nullptr;
  ChangeAllLatinToStar_C(str_2);
  BOOST_TEST(str_2 == nullptr);
}

BOOST_AUTO_TEST_CASE(Extra_test) {
  char str[] = "Hello123!@#$";
  const char expected[] = "*****123!@#$";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "Hello123World456";
  const char expected_2[] = "*****123*****456";
  ChangeAllLatinToStar_C(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "Hello!@#$%^&*()_+World";
  const char expected_3[] = "*****!@#$%^&*()_+*****";
  ChangeAllLatinToStar_C(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);

  char str_4[] = "123!@#$%^&*()";
  const char expected_4[] = "123!@#$%^&*()";
  ChangeAllLatinToStar_C(str_4);
  BOOST_TEST(std::strcmp(str_4, expected_4) == 0);

  char str_5[] = "The price is $19.99 or €17.50";
  const char expected_5[] = "*** ***** ** $19.99 ** €17.50";
  ChangeAllLatinToStar_C(str_5);
  BOOST_TEST(std::strcmp(str_5, expected_5) == 0);
}

BOOST_AUTO_TEST_CASE(Long_test) {
  char str[] = "ThisIsAVeryLongStringWithLotsOfLatinCharacters";
  const char expected[] = "**********************************************";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Repeat_test) {
  char str[] = "aaaabbbcccdddeeefff";
  const char expected[] = "*******************";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Special_test) {
  char str[] = "Hello\nWorld\tTest";
  const char expected[] = "*****\n*****\t****";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "Hello\nWorld";
  const char expected_2[] = "*****\n*****";
  ChangeAllLatinToStar_C(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "Hello\tWorld";
  const char expected_3[] = "*****\t*****";
  ChangeAllLatinToStar_C(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);

  char str_4[] = "Hello\nWorld\tTest";
  const char expected_4[] = "*****\n*****\t****";
  ChangeAllLatinToStar_C(str_4);
  BOOST_TEST(std::strcmp(str_4, expected_4) == 0);
}

BOOST_AUTO_TEST_CASE(French_test) {
  char str[] = "Bonjour, Hélène!";
  const char expected[] = "*******, *é*è**!";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Math_test) {
  char str[] = "x^2 + y^2 = z^2";
  const char expected[] = "*^2 + *^2 = *^2";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_SUITE_END()
