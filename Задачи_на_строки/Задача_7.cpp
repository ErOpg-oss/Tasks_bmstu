#include <iostream>
#include <cstring>

int main() {
    char str[100];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 100);
    
    char result[200] = "";
    int index = 0;
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        int count = 1;
        while (i + 1 < length && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        result[index++] = str[i];
        result[index++] = '0' + count;
    }
    result[index] = '\0';
    
    std::cout << "Сжатая строка: " << result << std::endl;
    return 0;
}
