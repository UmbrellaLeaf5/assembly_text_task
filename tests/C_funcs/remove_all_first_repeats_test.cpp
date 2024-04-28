#include <boost/test/unit_test.hpp>
#include <cctype>
#include <cstring>

extern "C" void RemoveAllFirstRepeats_C(char* str);

BOOST_AUTO_TEST_SUITE(RemoveAllFirstRepeats_C_Tests)

BOOST_AUTO_TEST_CASE(Simple_test) {
  char str[] = "abcd";
  const char expected[] = "bcd";

  RemoveAllFirstRepeats_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "aaaa";
  const char expected_2[] = "";

  RemoveAllFirstRepeats_C(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "abcacbc";
  const char expected_3[] = "bccbc";

  RemoveAllFirstRepeats_C(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);
}

BOOST_AUTO_TEST_CASE(Long_test) {
  char str[] = "aaaabbbbccccddddeeeeffffffff";
  const char expected[] = "bbbbccccddddeeeeffffffff";

  RemoveAllFirstRepeats_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  const char* expected_2 = "";

  RemoveAllFirstRepeats_C(str_2);
  BOOST_TEST(strcmp(str_2, expected_2) == 0);

  char str_3[] =
      "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrst"
      "uvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmn"
      "opqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefgh"
      "ijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
  const char* expected_3 =
      "bcdefghijklmnopqrstuvwxyzbcdefghijklmnopqrstuvwxyzbcdefghijklmnopqrst"
      "uvwxyzbcdefghijklmnopqrstuvwxyzbcdefghijklmnopqrstuvwxyzbcdefghijklmn"
      "opqrstuvwxyzbcdefghijklmnopqrstuvwxyzbcdefghijklmnopqrstuvwxyzbcdefgh"
      "ijklmnopqrstuvwxyzbcdefghijklmnopqrstuvwxyz";

  RemoveAllFirstRepeats_C(str_3);
  BOOST_TEST(strcmp(str_3, expected_3) == 0);
}

BOOST_AUTO_TEST_CASE(EmptyStr_test) {
  char str[] = "";
  const char expected[] = "";

  RemoveAllFirstRepeats_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);
}

BOOST_AUTO_TEST_CASE(Extra_test) {
  char str[] = "@#$%^&*()_+cd@#$%^&*()_+";
  const char* expected = "#$%^&*()_+cd#$%^&*()_+";

  RemoveAllFirstRepeats_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "abc   def   ";
  const char* expected_2 = "bc   def   ";

  RemoveAllFirstRepeats_C(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "abcδεζηθ";
  const char* expected_3 = "bcδεζηθ";

  RemoveAllFirstRepeats_C(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);
}

BOOST_AUTO_TEST_CASE(Special_test) {
  char str[] = "a\tb\tc\td";
  const char* expected = "\tb\tc\td";

  RemoveAllFirstRepeats_C(str);
  BOOST_TEST(std::strcmp(str, expected) == 0);

  char str_2[] = "a\nb\nc\nd";
  const char* expected_2 = "\nb\nc\nd";

  RemoveAllFirstRepeats_C(str_2);
  BOOST_TEST(std::strcmp(str_2, expected_2) == 0);

  char str_3[] = "a\tb\nc\rd\0e";
  const char* expected_3 = "\tb\nc\rd\0e";

  RemoveAllFirstRepeats_C(str_3);
  BOOST_TEST(std::strcmp(str_3, expected_3) == 0);
}

BOOST_AUTO_TEST_SUITE_END()
