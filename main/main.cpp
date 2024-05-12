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
 * @brief Проверяет свойство текста: текст начинается заглавной латинской буквой
 * и оканчивается заглавной латинской буквой
 * @param str: входной текст
 * @return true: свойство выполняется
 * @return false: свойство не выполняется
 */
extern "C" bool IsStartsAndEndsWithCapital_C(char const* str);

/**
 * @brief Производит операцию над текстом: заменить каждую латинскую букву
 * символом '*'
 * @param str: входной текст
 */
extern "C" void ChangeAllLatinToStar_C(char* str);

/**
 * @brief Производит операцию над текстом: удалить из текста все повторные
 * вхождения его первого символа
 * @param str: входной текст
 */
extern "C" void RemoveAllFirstRepeats_C(char* str);

int main() { return 0; }

// TODO: сделать в main полноценный ввод текста с консоли
