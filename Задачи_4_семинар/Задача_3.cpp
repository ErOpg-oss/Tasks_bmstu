#include <iostream>

int main() {
    std::cout << "Проверка коллинеарности трех точек в пространстве" << std::endl;
    
    double x1, y1, x2, y2, x3, y3;
    
    std::cout << "Введите координаты точки A (x1 y1): ";
    std::cin >> x1 >> y1;
    
    std::cout << "Введите координаты точки B (x2 y2): ";
    std::cin >> x2 >> y2;
    
    std::cout << "Введите координаты точки C (x3 y3): ";
    std::cin >> x3 >> y3;
    
    double det = x1 * (y2 - y3) - y1 * (x2 - x3) + (x2 * y3 - x3 * y2);
    
    if (det == 0) {
        std::cout << "Точки коллинеарны" << std::endl;
    } else {
        std::cout << "Точки не коллинеарны" << std::endl;
    }
    
    return 0;
}