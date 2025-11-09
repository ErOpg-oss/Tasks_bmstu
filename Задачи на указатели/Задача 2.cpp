#include <iostream>

void myStrCopy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char dest[20];
    const char* src = "Hello World";
    myStrCopy(dest, src);
    std::cout << dest << std::endl;
    return 0;
}
