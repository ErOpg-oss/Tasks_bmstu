#include <iostream>
int main() {
    std::cout << "Дан массив из 10 целых чисел. Если минимальный элемент массива расположен на 5 месте, а максимальный – на 10 месте, то подсчитать среднее арифметическое максимального и минимального элементов массива." << std::endl;

    const int n = 10;
    double arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int minPos = 0, maxPos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minPos]) minPos = i;
        if (arr[i] > arr[maxPos]) maxPos = i;
    }

    if (maxPos == 9 && minPos == 4) 
    {
        std::cout << "Среднее арифметическое: " << (arr[minPos] + arr[maxPos]) / 2.0 << std::endl;
    } 
    else 
    {
        std::cout << "Условие не выполнено: минимальный элемент не на 5-м месте или максимальный не на 10-м." << std::endl;
    }
}
