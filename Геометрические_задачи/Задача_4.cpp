#include <iostream>
#include <cmath>
#include <algorithm>

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double findMaxDiagonal(double dots[4][2]) {
    double maxDiag = 0.0;
    
    // Находим максимальное расстояние между всеми парами вершин
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            double dist = distance(dots[i][0], dots[i][1], dots[j][0], dots[j][1]);
            if (dist > maxDiag) {
                maxDiag = dist;
            }
        }
    }
    
    return maxDiag;
}

int main() {
    double dots[4][2];

    std::cout << "Программа находит длину диагонали прямоугольника по координатам вершин.\n";
    std::cout << "Введите координаты 4 вершин x y:\n";

    for (int i = 0; i < 4; ++i) {
        std::cout << "Вершина " << i + 1 << ": ";
        std::cin >> dots[i][0] >> dots[i][1];
    }

    double diag = findMaxDiagonal(dots);
    std::cout << "Длина диагонали прямоугольника: " << diag << std::endl;

    return 0;
}