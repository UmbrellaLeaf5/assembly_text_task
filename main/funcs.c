#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

// ---------------------- helping static functions ----------------------

__attribute__((sysv_abi)) static char LastOf(const char* str) {
  assert(str);

  char c = '\0';
  for (; *str != '\0'; ++str) c = *str;

  return c;
}

__attribute__((sysv_abi)) static char FirstOf(const char* str) {
  assert(str);
  return str[0];
}

// ----------------------     task functions     ----------------------

__attribute__((sysv_abi)) bool IsStartsAndEndsWithCapital_C(char const* str) {
  assert(str);

  char f = FirstOf(str);
  char l = LastOf(str);

  return isupper(f) == isupper(l);
}

__attribute__((sysv_abi)) void ChangeAllLatinToStar_C(char* str) {}

__attribute__((sysv_abi)) void RemoveAllFirstRepeats_C(char* str) {}
