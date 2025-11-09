#include <iostream>

void removeSpaces(char* str) {
    char* dest = str;
    while (*str != '\0') {
        if (*str != ' ') {
            *dest = *str;
            dest++;
        }
        str++;
    }
    *dest = '\0';
}

int main() {
    char str[] = "h e l l o w o r l d";
    removeSpaces(str);
    std::cout << str << std::endl;
    return 0;
}
