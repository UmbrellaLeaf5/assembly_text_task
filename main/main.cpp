#include <cstring>
#include <iostream>

/**
 * @brief Проверяет свойство текста: текст начинается заглавной латинской буквой
 * и оканчивается заглавной латинской буквой
 * @param str: входной текст
 * @return true: свойство выполняется
 * @return false: свойство не выполняется
 */
extern "C" __attribute__((sysv_abi)) bool IsStartsAndEndsWithCapital(
    char const* str);

/**
 * @brief Производит операцию над текстом: заменить каждую латинскую букву
 * символом '*'
 * @param str: входной текст
 */
extern "C" __attribute__((sysv_abi)) void ChangeAllLatinToStar(char* str);

/**
 * @brief Производит операцию над текстом: удалить из текста все повторные
 * вхождения его первого символа
 * @param str: входной текст
 */
extern "C" __attribute__((sysv_abi)) void RemoveAllFirstRepeats(char* str);

/**
 * @brief Отлавливает Ctrl+C
 * @param signal_num: номер сигнала
 */
static void SigintHandler(const int signal_num) {
  std::cout << std::endl << "Exiting the program..." << std::endl;
  exit(signal_num);
}

static char str[SHRT_MAX];
static char str_copy[SHRT_MAX];

int main() {
  signal(SIGINT, SigintHandler);

  for (;;) {
    // getting a line
    std::cout << "Enter the text (one string): " << std::endl;
    std::cin.getline(str, SHRT_MAX);
    std::cout << std::endl;

    // if cin fail
    if (std::cin.eof()) break;

    strcpy(str_copy, str);

    for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);  // to lower case
    if (!strcmp(str, "quit") || !strcmp(str, "exit")) break;

    if (IsStartsAndEndsWithCapital(str_copy)) {
      std::cout << " @property: Begins and ends with a capital letter."
                << std::endl;
      ChangeAllLatinToStar(str_copy);
      std::cout << "Modified string (@rule: change all latin to star): "
                << std::endl
                << str_copy << std::endl
                << std::endl;
    } else {
      std::cout << " @property: Does not begin or end with a capital letter."
                << std::endl;
      RemoveAllFirstRepeats(str_copy);
      std::cout << "Modified string (@rule: remove all first repeats): "
                << std::endl
                << str_copy << std::endl
                << std::endl;
    }
  }

  std::cout << "Exiting the program..." << std::endl;
  return 0;
}
