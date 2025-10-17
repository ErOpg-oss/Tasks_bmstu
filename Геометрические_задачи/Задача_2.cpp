#include <iostream>
#include <cmath>
#include <vector>

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double perimeter(const std::vector<std::vector<double>>& dots) {
    int n = dots.size();
    if (n < 3) {
        std::cout << "Для многоугольника нужно минимум 3 вершины!" << std::endl;
        return 0.0;
    }
    
    double perimeter = 0.0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        perimeter += distance(dots[i][0], dots[i][1], dots[j][0], dots[j][1]);
    }    
    return perimeter;
}

int main() {
    int n;
    std::cout << "Программа находит периметр многоугольника по координатам точек." << std::endl;
    std::cout << "Введите количество вершин: ";
    std::cin >> n;
    
    if (n < 3) {
        std::cout << "Многоугольник должен иметь минимум 3 вершины!" << std::endl;
        return 1;
    }
    
    std::vector<std::vector<double>> dots(n, std::vector<double>(2));
    
    std::cout << "Введите координаты вершин x y:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Вершина " << (i + 1) << ": ";
        std::cin >> dots[i][0] >> dots[i][1];
    }
    
    double result = perimeter(dots);
    std::cout << "Периметр " << n << "-угольника: " << result << std::endl;
    
    return 0;
}