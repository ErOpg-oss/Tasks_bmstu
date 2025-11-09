#include <iostream>

void myStrCat(char* dest, const char* src) {
    while (*dest != '\0') dest++;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int main() {
    char dest[50] = "Hello ";
    const char* src = "World";
    myStrCat(dest, src);
    std::cout << dest << std::endl;
    return 0;
}
