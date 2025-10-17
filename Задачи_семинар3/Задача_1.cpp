#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Даны натуральные числа А1, ...,Аn. Определить количество членов Аk последовательности А1, ...,Аn, удовлетворяющих условию А[k]>2^k"<<std::endl;
    std::cout << "Введите количество элементов в последовательности: ";
    std::cin >> n;

    int A[n]; 


    for (int k = 0; k < n; ++k) {
        std::cout << "Введите элемент: ";
        std::cin >> A[k];
    }

    int count = 0;


    for (int k = 0; k < n; ++k) {
        if (A[k] > pow(2, k+1)) {
            ++count;
        }
    }

    std::cout << "Количество элементов, удовлетворяющих условию A[k] > 2^k: " << count << std::endl;

    return 0;
}

