#include <iostream>

void reverse(char* str) {
    char* start = str;
    char* end = str;
    while (*end != '\0') end++;
    end--;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "hello";
    reverse(str);
    std::cout << str << std::endl;
    return 0;
}
