#include <iostream>

bool isPalindrome(const char* str) {
    const char* start = str;
    const char* end = str;
    while (*end != '\0') end++;
    end--;
    while (start < end) {
        if (*start != *end) return false;
        start++;
        end--;
    }
    return true;
}

int main() {
    const char* test1 = "radar";
    const char* test2 = "hello";
    std::cout << isPalindrome(test1) << std::endl;
    std::cout << isPalindrome(test2) << std::endl;
    return 0;
}
