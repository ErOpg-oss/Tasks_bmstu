#include <iostream>
#include <cstring>

int main() {
    char str[200];
    char n;
    std::cout << "Введите строку: ";
    std::cin.getline(str, 200);
    std::cout << "Введите символ для удаления: ";
    std::cin >> n;

    char result[200] = "";
    int lenght = strlen(str);

    for (int i = 0; i < lenght; ++i) {
        if (str[i] != n) {
            int res = strlen(result);
            result[res] = str[i];
            result[res + 1] = '\0';
        }
    }

    std::cout << "Результат: " << result << std::endl;

    return 0;
}
