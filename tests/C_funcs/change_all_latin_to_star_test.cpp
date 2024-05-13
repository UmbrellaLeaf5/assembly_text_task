#include <boost/test/unit_test.hpp>

/**
 * @brief Производит операцию над текстом: заменить каждую латинскую букву
 * символом '*'
 * @param str: входной текст
 */
extern "C" void ChangeAllLatinToStar(char* str);

BOOST_AUTO_TEST_SUITE(ChangeAllLatinToStar_C_Tests)

BOOST_AUTO_TEST_CASE(Simple_test) {
  char str[] = "HelloWorld";
  const char expected[] = "**********";

  ChangeAllLatinToStar(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "H1e2l3l4o5W6o7r8l9d";
  const char expected_2[] = "*1*2*3*4*5*6*7*8*9*";

  ChangeAllLatinToStar(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);
}

BOOST_AUTO_TEST_CASE(Long_test) {
  char str[] = "ThisIsAVeryLongStringWithLotsOfLatinCharacters";
  const char expected[] = "**********************************************";

  ChangeAllLatinToStar(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "aaaabbbcccdddeeefff";
  const char expected_2[] = "*******************";

  ChangeAllLatinToStar(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);
}

BOOST_AUTO_TEST_CASE(EmptyStr_test) {
  char str[] = "";

  ChangeAllLatinToStar(str);
  BOOST_TEST(std::strlen(str) == 0);

  char* str_2 = nullptr;

  ChangeAllLatinToStar(str_2);
  BOOST_TEST(str_2 == nullptr);
}

BOOST_AUTO_TEST_CASE(Extra_test) {
  char str[] = "Hello123!@#$";
  const char expected[] = "*****123!@#$";

  ChangeAllLatinToStar(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "Hello123World456";
  const char expected_2[] = "*****123*****456";

  ChangeAllLatinToStar(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "Hello!@#$%^&*()_+World";
  const char expected_3[] = "*****!@#$%^&*()_+*****";

  ChangeAllLatinToStar(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);

  char str_4[] = "123!@#$%^&*()";
  const char expected_4[] = "123!@#$%^&*()";

  ChangeAllLatinToStar(str_4);
  BOOST_TEST(std::strcmp(str_4, expected_4) == 0);

  char str_5[] = "The price is $19.99 or €17.50";
  const char expected_5[] = "*** ***** ** $19.99 ** €17.50";

  ChangeAllLatinToStar(str_5);
  BOOST_TEST(std::strcmp(str_5, expected_5) == 0);
}

BOOST_AUTO_TEST_CASE(French_test) {
  char str[] = "Bonjour, Hélène!";
  const char expected[] = "*******, *é*è**!";

  ChangeAllLatinToStar(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Math_test) {
  char str[] = "x^2 + y^2 = z^2";
  const char expected[] = "*^2 + *^2 = *^2";

  ChangeAllLatinToStar(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Special_test) {
  char str[] = "Hello\nWorld\tTest";
  const char expected[] = "*****\n*****\t****";

  ChangeAllLatinToStar(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "Hello\nWorld";
  const char expected_2[] = "*****\n*****";

  ChangeAllLatinToStar(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "Hello\tWorld";
  const char expected_3[] = "*****\t*****";

  ChangeAllLatinToStar(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);

  char str_4[] = "Hello\nWorld\tTest";
  const char expected_4[] = "*****\n*****\t****";

  ChangeAllLatinToStar(str_4);
  BOOST_TEST(std::strcmp(str_4, expected_4) == 0);
}

BOOST_AUTO_TEST_SUITE_END()
