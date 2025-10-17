#include <iostream>

int main() {
    int age;
    std::cout << "Проверка возраста пользователя.";

    if (age < 18) 
    {
        std::cout << "Вы слишком молоды\n";
    } 
    else if (age <= 60) 
    {
        std::cout << "Вы взрослый\n";
    } 
    else 
    {
        std::cout << "Вы старше 60\n";
    }

    return 0;
}