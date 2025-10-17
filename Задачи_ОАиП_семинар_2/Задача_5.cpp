#include <iostream>

int main() {
    int number;
    char answer = 'y';
    std::cout << "Проверка делимости числа на 3 и 5.";

    
    std::cout << "Введите число: ";
    std::cin >> number;

    if (number % 3 == 0 && number % 5 == 0) 
    {
        std::cout << "Число делится на 3 и на 5 одновременно";
    } 
    else if (number % 3 == 0) 
    {
        std::cout << "Число делится на 3";
    } 
    else if (number % 5 == 0) 
    {
        std::cout << "Число делится на 5";
    } 
    else
    {
        std::cout << "Число не делится ни на 3, ни на 5";
    }

    return 0;
}