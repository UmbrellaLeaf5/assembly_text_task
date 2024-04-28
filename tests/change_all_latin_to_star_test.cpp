#include <boost/test/unit_test.hpp>
#include <cctype>
#include <cstring>

extern "C" void ChangeAllLatinToStar_C(char* str);

BOOST_AUTO_TEST_SUITE(ChangeAllLatinToStar_C_Tests)

BOOST_AUTO_TEST_CASE(Simple_test) {
  char str[] = "HelloWorld";
  char expected[] = "**********";
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
  char expected[] = "*****123!@#$";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "Hello123World456";
  char expected_2[] = "*****123*****456";
  ChangeAllLatinToStar_C(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "Hello!@#$%^&*()_+World";
  char expected_3[] = "*****!@#$%^&*()_+*****";
  ChangeAllLatinToStar_C(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);

  char str_4[] = "123!@#$%^&*()";
  char expected_4[] = "123!@#$%^&*()";
  ChangeAllLatinToStar_C(str_4);
  BOOST_TEST(std::strcmp(str_4, expected_4) == 0);

  char str_5[] = "The price is $19.99 or €17.50";
  char expected_5[] = "*** ***** ** $19.99 ** €17.50";
  ChangeAllLatinToStar_C(str_5);
  BOOST_TEST(std::strcmp(str_5, expected_5) == 0);
}

BOOST_AUTO_TEST_CASE(Long_test) {
  char str[] = "ThisIsAVeryLongStringWithLotsOfLatinCharacters";
  char expected[] = "**********************************************";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Repeat_test) {
  char str[] = "aaaabbbcccdddeeefff";
  char expected[] = "*******************";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Special_test) {
  char str[] = "Hello\nWorld\tTest";
  char expected[] = "*****\n*****\t****";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "Hello\nWorld";
  char expected_2[] = "*****\n*****";
  ChangeAllLatinToStar_C(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "Hello\tWorld";
  char expected_3[] = "*****\t*****";
  ChangeAllLatinToStar_C(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);

  char str_4[] = "Hello\nWorld\tTest";
  char expected_4[] = "*****\n*****\t****";
  ChangeAllLatinToStar_C(str_4);
  BOOST_TEST(std::strcmp(str_4, expected_4) == 0);
}

BOOST_AUTO_TEST_CASE(French_test) {
  char str[] = "Bonjour, Hélène!";
  char expected[] = "*******, *é*è**!";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Math_test) {
  char str[] = "x^2 + y^2 = z^2";
  char expected[] = "*^2 + *^2 = *^2";
  ChangeAllLatinToStar_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_SUITE_END()
