#include <iostream>
#include <cmath>

int main() {
    std::cout << "Поворот точки вокруг начала координат на угол" << std::endl;
    std::cout << "Введите координаты точки (x y) и угол θ в градусах: ";
    
    double x, y, angle;
    std::cin >> x >> y >> angle;
    
    double x_new = x * cos(angle * M_PI / 180.0) + y * sin(angle * M_PI / 180.0);
    double y_new = -x * sin(angle * M_PI / 180.0) + y * cos(angle * M_PI / 180.0);
    
    std::cout << "Новые координаты точки: (" << x_new << ", " << y_new << ")" << std::endl;
    
    return 0;
}