#include <iostream>
#include <cmath>


bool Collinear(double x1, double y1, double x2, double y2, double x3, double y3) {
    double crossProduct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    return crossProduct == 0;
}

int main() {
    double points[3][2];

    std::cout << "Программа проверяет, лежат ли три точки на одной прямой.\n";
    std::cout << "Введите координаты трёх точек x y";

    for (int i = 0; i < 3; ++i) std::cin >> points[i][0] >> points[i][1];

    if (Collinear(points[0][0], points[0][1], points[1][0], points[1][1], points[2][0], points[2][1])) {
        std::cout << "Точки лежат на одной прямой.\n";
    } else {
        std::cout << "Точки не лежат на одной прямой.\n";
    }

    return 0;
}
