#include <iostream>
#include <cstring>

void reverseWord(char str[], int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char str[100];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);
    
    int start = 0;
    for (int i = 0; i <= strlen(str); i++) {

        if (str[i] == ' ' || str[i] == '\0') {
                reverseWord(str, start, i - 1);
                start = i + 1;
            }
        }
    
    std::cout << "Результат: " << str << std::endl;
    return 0;
}
