#include <iostream>
#include <cstring>

int main() {
    char str1[100], str2[100];
    
    std::cout << "Введите первую строку: ";
    std::cin.getline(str1, 100);
    std::cout << "Введите вторую строку: ";
    std::cin.getline(str2, 100);
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Создаем двумерный массив dp
    int dp[100][100] = {0};
    int maxLen = 0;
    int endIndex = 0;
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i - 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    
    if (maxLen > 0) {
        std::cout << "Наибольшая общая подстрока: \"";
        for (int i = endIndex - maxLen + 1; i <= endIndex; i++) {
            std::cout << str1[i];
        }
        std::cout << "\"" << std::endl;
    } else {
        std::cout << "Общих подстрок не найдено" << std::endl;
    }
    
    return 0;
}