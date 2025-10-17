#include <iostream>
int main() {
    std::cout << "Дан массив из 15 вещественных чисел. Если минимальный элемент массива находится на 2 месте, а максимальный на 1 месте в массиве, то все элементы массива уменьшить в 2 раза." << std::endl;
    
    const int n = 15;
    double arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int minPos = 0, maxPos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minPos]) minPos = i;
        if (arr[i] > arr[maxPos]) maxPos = i;
    }

    if (maxPos == 0 && minPos == 1) 
    {
        for (int i = 0; i < n; i++)
            {
                arr[i] = arr[i]/2;
                std::cout << arr[i] << " ";
            }
    } 
    else 
    {
        std::cout << "Условие не выполнено" << std::endl;
    }
}
