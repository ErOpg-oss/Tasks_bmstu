#include <iostream>

void replaceSpaces(char* str) {
    while (*str != '\0') {
        if (*str == ' ') *str = '_';
        str++;
    }
}

int main() {
    char str[] = "hello world test";
    replaceSpaces(str);
    std::cout << str << std::endl;
    return 0;
}
