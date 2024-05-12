#include <ctype.h>
#include <stdbool.h>

// ---------------------- helping static functions ----------------------

static char LastOf_С(const char* s) {
  if (!s) return '\0';

  char c = '\0';
  for (; *s != '\0'; ++s) c = *s;

  return c;
}

static char FirstOf_С(const char* s) {
  if (!s) return '\0';
  return s[0];
}

// ----------------------      task functions      ----------------------

bool IsStartsAndEndsWithCapital_C(char const* s) {
  char f = FirstOf_С(s);
  char l = LastOf_С(s);

  if (isupper(f))
    if (isupper(l)) return true;

  // else:
  return false;
}

void ChangeAllLatinToStar_C(char* s) {
  if (!s) return;

  for (; *s != '\0'; ++s)
    if (isalpha(*s)) *s = '*';
}

void RemoveAllFirstRepeats_C(char* s) {
  if (!s) return;

  char f = FirstOf_С(s);
  char* mod_str = s;

  for (; *s != '\0'; ++s)
    if (*s != f) {
      *mod_str = *s;
      mod_str++;
    }

  *mod_str = '\0';
}
