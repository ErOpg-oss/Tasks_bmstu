#include <iostream>
int main() {
    std::cout << "Дан массив из 10 целых чисел. Если максимальный элемент находится на 2 месте, а минимальный элемент на 5 месте, то все элементы, расположенные от минимального элемента и до конца массива, установить равными максимальному элементу." << std::endl;
    
    const int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int minPos = 0, maxPos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minPos]) minPos = i;
        if (arr[i] > arr[maxPos]) maxPos = i;
    }

    if (maxPos == 1 && minPos == 4) 
    {
        for (int i = minPos; i < n ; i++) 
        {
            arr[i] = arr[maxPos];
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