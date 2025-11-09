#include <iostream>

int myStrCmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int main() {
    const char* str1 = "abc";
    const char* str2 = "abd";
    std::cout << myStrCmp(str1, str2) << std::endl;
    return 0;
}
