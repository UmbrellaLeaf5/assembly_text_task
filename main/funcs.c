#include <ctype.h>
#include <stdbool.h>

// ---------------------- helping static functions ----------------------

static char LastOf(const char* s) {
  if (!s) return '\0';

  char c = '\0';
  for (; *s != '\0'; ++s) c = *s;

  return c;
}

static char FirstOf(const char* s) {
  if (!s) return '\0';
  return s[0];
}

// ----------------------      task functions      ----------------------

/**
 * @brief Проверяет свойство текста: текст начинается заглавной латинской буквой
 * и оканчивается заглавной латинской буквой
 * @param str: входной текст
 * @return true: свойство выполняется
 * @return false: свойство не выполняется
 */
bool IsStartsAndEndsWithCapital(char const* s) {
  char f = FirstOf(s);
  char l = LastOf(s);

  if (isupper(f))
    if (isupper(l)) return true;

  // else:
  return false;
}

/**
 * @brief Производит операцию над текстом: заменить каждую латинскую букву
 * символом '*'
 * @param str: входной текст
 */
void ChangeAllLatinToStar(char* s) {
  if (!s) return;

  for (; *s != '\0'; ++s)
    if (isalpha(*s)) *s = '*';
}

/**
 * @brief Производит операцию над текстом: удалить из текста все повторные
 * вхождения его первого символа
 * @param str: входной текст
 */
void RemoveAllFirstRepeats(char* s) {
  if (!s) return;

  char f = FirstOf(s);
  char* mod_str = s;

  for (; *s != '\0'; ++s)
    if (*s != f) {
      *mod_str = *s;
      mod_str++;
    }

  *mod_str = '\0';
}
