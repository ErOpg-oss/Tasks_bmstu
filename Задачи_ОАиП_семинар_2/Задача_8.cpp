#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    std::string vowels = "aeiouAEIOU";
    int count = 0;

    for (char ch : s) {
        if (vowels.find(ch) != std::string::npos) {
            count++;
        }
    }

    std::cout << count;
    return 0;
}