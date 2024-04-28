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

// ----------------------      task functions      ----------------------

bool IsStartsAndEndsWithCapital_C(char const* str) {
  assert(str);

  char f = FirstOf(str);
  char l = LastOf(str);

  return isupper(f) == isupper(l);
}

void ChangeAllLatinToStar_C(char* str) {
  if (!str) return;

  for (; *str != '\0'; ++str)
    if (isalpha(*str)) *str = '*';
}

void RemoveAllFirstRepeats_C(char* str) {
  char f = FirstOf(str);
  char* mod_str = str;

  for (; *str != '\0'; ++str)
    if (*str != f) {
      *mod_str = *str;
      mod_str++;
    }

  *mod_str = '\0';
}
