#include <iostream>

int main()
{
    int c, temp;
 
    std::cout<<"Пользователь вводит температуру в градусах Цельсия. Программа переводит её в градусы"<<std::endl;
    std::cin>>c;
    temp = (c * 9.0 / 5.0) + 32;
    std::cout<<"Температура в градусах: "<<temp<<std::endl;

            
    

    return 0;
}