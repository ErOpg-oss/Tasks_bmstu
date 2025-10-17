#include <iostream>
#include <algorithm>

int main() {
    std::cout << "Дана последовательность из 15 вещественных чисел. Наименьшее число в этой последовательности поменять местами с первым числом и наибольшее число поменять местами с последним числом в этой последовательности" << std::endl;
    
    int n = 15;
    double arr[n];
    
    for (int i = 0; i < n; i++) 
    {
        std::cin >> arr[i];
    }
    
    int minPos = 0, maxPos = 0;
    
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] < arr[minPos]) minPos = i;
        if (arr[i] > arr[maxPos]) maxPos = i;
    }

    std::swap(arr[0], arr[minPos]);
    
    if (maxPos == 0) maxPos = minPos;
    
    std::swap(arr[n-1], arr[maxPos]);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}