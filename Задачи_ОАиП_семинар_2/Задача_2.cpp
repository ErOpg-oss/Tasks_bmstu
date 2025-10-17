#include <iostream>

int main()
{
    int lang, wight;
    
    if (lang < 0) 
    {
        std::cout << "Длина не может быть отрицательной!" << std::endl;
        return 1;
    }

    std::cout<<"Пользователь вводит длину и ширину прямоугольника. Программа вычисляет и выводит площадь."<<std::endl;
    std::cin>>lang;
    std::cin>>wight;
    std::cout<<"Площадь равна: "<<lang*wight<<std::endl;

    return 0;
}