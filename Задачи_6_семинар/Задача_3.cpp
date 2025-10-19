#include <iostream>
#include <cstring>

int main() {
    char str[200];
    char oldSub[50];
    char newSub[50];
    std::cout << "Введите строку: ";
    std::cin.getline(str, 200);
    std::cout << "Введите подстроку для замены: ";
    std::cin.getline(oldSub, 50);
    std::cout << "Введите новую подстроку: ";
    std::cin.getline(newSub, 50);

    char result[400] = "";
    int len = strlen(str);
    int oldLen = strlen(oldSub);
    int newLen = strlen(newSub);

    for (int i = 0; i < len; ) {
        bool found = true;
        for (int j = 0; j < oldLen; j++) {
            if (str[i + j] != oldSub[j]) {
                found = false;
                break;
            }
        }

        if (found) {
            strcat(result, newSub);
            i += oldLen;
        } 
        else {
            int resLen = strlen(result);
            result[resLen] = str[i];
            result[resLen + 1] = '\0';
            i++;
        }
    }

    std::cout << "Результат: " << result << std::endl;

    return 0;
}