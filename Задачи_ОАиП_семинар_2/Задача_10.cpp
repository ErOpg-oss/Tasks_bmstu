#include <iostream>

int main()
{
   int number;
   std::cout<<"Пользователь вводит число. Программа сообщает, положительное оно, отрицательное или равно нулю."<<std::endl;
   std::cin>>number;
   
   if (number == 0)
   {
    std::cout<<"Равна нулю"<<std::endl;
   }
   else if (number < 0)
   {
    std::cout<<"Отрицательное число"<<std::endl;
   }
   else
   {
    std::cout<<"Положительное число"<<std::endl;
   }
   return 0;
}