#include <iostream>
#include <algorithm>

int main() {
    const int n = 15;
    double arr[n];
    std::cout << "Дан массив из 15 вещественных чисел. Если максимальный элемент массива предшествует минимальному элементу, то подсчитать произведение минимального и максимального элементов.";
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int minPos = 0;
    int maxPos = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minPos]) {
            minPos = i;
        }
        if (arr[i] > arr[maxPos]) {
            maxPos = i;
        }
    }

    if (maxPos < minPos) {
        double product = arr[minPos] * arr[maxPos];
        std::cout << "Произведение: " << product << std::endl;
    }

    std::swap(arr[0], arr[minPos]);
    if (maxPos == 0) maxPos = minPos;
    std::swap(arr[n - 1], arr[maxPos]);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}