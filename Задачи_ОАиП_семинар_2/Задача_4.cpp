#include <iostream>

int main()
{
    int number;

    std::cout<<"Пользователь вводит целое число. Программа сообщает, является ли число четным или нечетным.";

    std::cout<<"Введите число: ";
    std::cin>>number;
    if (number%2 == 0)
    {
        std::cout<<"Ваше число четное"<<std::endl;
    }
    else
    {
        std::cout<<"Ваше число нечетное"<<std::endl;
    }
    return 0;
}