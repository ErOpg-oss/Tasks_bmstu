#include <iostream>

int countChar(const char* str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) count++;
        str++;
    }
    return count;
}

int main() {
    const char* str = "hello world";
    char ch = 'l';
    std::cout << countChar(str, ch) << std::endl;
    return 0;
}
