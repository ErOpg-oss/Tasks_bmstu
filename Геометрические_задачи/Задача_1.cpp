#include <iostream>
#include <cmath> 

double Area(double dot[3][2]) {

    double x1 = dot[0][0], y1 = dot[0][1];
    double x2 = dot[1][0], y2 = dot[1][1];
    double x3 = dot[2][0], y3 = dot[2][1];

    return 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main() {
    double dot[3][2];

    std::cout << "Введите координаты 3 вершин треугольника x y:" <<std::endl;
    for (int i = 0; i < 3; i++) std::cin >> dot[i][0] >> dot[i][1];

    double area = Area(dot);
    std::cout << "Площадь треугольника: " << area <<std::endl;

    return 0;
}
