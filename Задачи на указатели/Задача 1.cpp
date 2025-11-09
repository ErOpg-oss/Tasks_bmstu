#include <iostream>

int myStrLen(const char* str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

int main() {
    const char* test = "Hello";
    std::cout << myStrLen(test) << std::endl;
    return 0;
}
