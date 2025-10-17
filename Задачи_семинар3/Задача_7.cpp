#include <iostream>
int main() {
    std::cout << "Дан массив из 15 целых чисел. Если минимальный или максимальный элемент равен 0, то обнулить элементы массива, предшествующие минимальному элементу в массиве." << std::endl;
    
    int n = 15;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int minPos = 0, maxPos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minPos]) minPos = i;
        if (arr[i] > arr[maxPos]) maxPos = i;
    }

    if (arr[maxPos] == 0 or arr[minPos] == 0) 
    {
        if (minPos > 0) 
        {
            for (int i = 0; i < minPos; i++) 
            {
                arr[i] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << " ";
        } 
    }
    else 
    {
        std::cout << "Условие не выполнено" << std::endl;
    }
}