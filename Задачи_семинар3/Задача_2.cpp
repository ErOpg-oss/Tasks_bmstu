#include <iostream>
#include <climits>

int main() {
    std::cout<<"Даны натуральные n и целые числа А1,...,Аn. Найти наибольшее из нечетных и количество четных чисел, входящих в последовательность А1,...,Аn."<<std::endl;
    std::cout<<"Введите сначало n, потом введите элементы последовательности"<<std::endl;
    
    int n;
    std::cin >> n;
    
    int A[n];
    
    for (int i = 0; i < n; i++) 
    {
        std::cin >> A[i];
    }
    int max = INT_MIN;
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        if (A[i] % 2 == 0) 
        {
            count += 1;
        }
        else if (A[i] > max)
        {
            max = A[i];
        }
    }


    if (max == INT_MIN)
    {
        std::cout << "Нет нечетных";
    }
    else 
    {
        std::cout<<"Максимальное нечетное число: "<<max<<std::endl;
        std::cout<<"Кол-во четных чисел: "<<count<<std::endl;
    }

    return 0;
}