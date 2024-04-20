#include <cstring>
#include <iostream>

extern "C" __attribute__((sysv_abi)) bool IsStartsAndEndsWithCapital(
    char const* str);
extern "C" __attribute__((sysv_abi)) void ChangeAllLatinToStar(char* str);
extern "C" __attribute__((sysv_abi)) void RemoveAllFirstRepeats(char* str);

extern "C" __attribute__((sysv_abi)) bool IsStartsAndEndsWithCapital_C(
    char const* str);
extern "C" __attribute__((sysv_abi)) void ChangeAllLatinToStar_C(char* str);
extern "C" __attribute__((sysv_abi)) void RemoveAllFirstRepeats_C(char* str);

int main() { return 0; }