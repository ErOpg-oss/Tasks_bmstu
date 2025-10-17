#include <iostream>

int main() {
    int n;
    std::cout << "Вывод таблицы квадратов чисел.";

    std::cout << "Введите число n: ";
    std::cin >> n;

    if (n < 0) 
    {
        std::cout << "n не может быть отрицательной!" << std::endl;
        return 1;
    }

    int i = 1;
    while (i <= n) 
    {
        std::cout << i << "^2 = " << i*i << std::endl;
        i++;
    }
    return 0;
}