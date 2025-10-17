#include <iostream>
#include <cmath>

int main() {
    std::cout << "Нахождение площади треугольника по координатам вершин" << std::endl;    
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    double det = x1 * (y2 - y3) - y1 * (x2 - x3) + (x2 * y3 - x3 * y2);
    double area = 0.5 * std::abs(det);
    
    std::cout << "Площадь треугольника: " << area << std::endl;
    
    return 0;
}