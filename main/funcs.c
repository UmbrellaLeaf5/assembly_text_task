#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

// ---------------------- helping static functions ----------------------

static char LastOf_С(const char* str) {
  assert(str);

  char c = '\0';
  for (; *str != '\0'; ++str) c = *str;

  return c;
}

static char FirstOf_С(const char* str) {
  assert(str);
  return str[0];
}

// ----------------------      task functions      ----------------------

bool IsStartsAndEndsWithCapital_C(char const* str) {
  char f = FirstOf_С(str);
  char l = LastOf_С(str);

  return isupper(f) && isupper(l);
}

void ChangeAllLatinToStar_C(char* str) {
  if (!str) return;

  for (; *str != '\0'; ++str)
    if (isalpha(*str)) *str = '*';
}

void RemoveAllFirstRepeats_C(char* str) {
  if (!str) return;

  char f = FirstOf_С(str);
  char* mod_str = str;

  for (; *str != '\0'; ++str)
    if (*str != f) {
      *mod_str = *str;
      mod_str++;
    }

  *mod_str = '\0';
}
