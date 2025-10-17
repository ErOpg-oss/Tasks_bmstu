#include <iostream>

int main() {
    std::cout << "Система уравнений:" << std::endl;
    std::cout << "2x + 3y = 13" << std::endl;
    std::cout << "5x - y = 9" << std::endl;
    std::cout << std::endl;
    
    double a1 = 2, b1 = 3, c1 = 13;
    double a2 = 5, b2 = -1, c2 = 9;
    
    double det = a1 * b2 - a2 * b1;
    double det_x = c1 * b2 - c2 * b1;
    double det_y = a1 * c2 - a2 * c1;
    
    double x = det_x / det;
    double y = det_y / det;
    
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    
    return 0;
}