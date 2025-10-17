#include <iostream>

int main()
{
    int number, sum = 0;
    std::cout<<"Пользователь вводит число n. Программа вычисляет сумму всех чисел от 1 до n, которые делятся на 2 или на 5.";
        
        std::cout<<"Введите число: ";
        std::cin>>number;
        for (int i = 1; i <= number; i++)
        {
            if (i%2 == 0 || i%5 == 0)
            {
                sum += i;
            }
            
        }
        std::cout<<"Сумма: "<<sum<<std::endl;
    
    return 0;
}