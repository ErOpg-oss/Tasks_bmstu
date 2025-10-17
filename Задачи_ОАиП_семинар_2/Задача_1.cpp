#include <iostream>

int main()
{   
    std::cout<<"Пользователь вводит длину в сантиметрах. Программа выводит количество полных метров и оставшиеся сантиметры"<<std::endl;
    int lang, change;  

    if (lang < 0) 
    {
        std::cout << "Длина не может быть отрицательной!" << std::endl;
        return 1;
    }

    std::cout<<"Введите кол-во сантиметров: ";
    std::cin>>lang;
    change =lang%100;
    std::cout<<"Кол-во метров: "<<lang/100<<std::endl;
    std::cout<<"Кол-во оставшихся сантиметров: "<<change<<std::endl;



    return 0;
}
