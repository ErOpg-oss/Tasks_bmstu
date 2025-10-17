#include <iostream>

int main() {
    std::cout << "Система уравнений:" << std::endl;
    std::cout << "3x - y + 2z = 5" << std::endl;
    std::cout << "2x + 4y - z = 6" << std::endl;
    std::cout << "x - 3y + z = 4" << std::endl;
    std::cout << std::endl;
    
    double a1 = 3, b1 = -1, c1 = 2, d1 = 5;
    double a2 = 2, b2 = 4, c2 = -1, d2 = 6;
    double a3 = 1, b3 = -3, c3 = 1, d3 = 4;
    
    double det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
    double det_x = d1 * (b2 * c3 - b3 * c2) - b1 * (d2 * c3 - d3 * c2) + c1 * (d2 * b3 - d3 * b2);
    double det_y = a1 * (d2 * c3 - d3 * c2) - d1 * (a2 * c3 - a3 * c2) + c1 * (a2 * d3 - a3 * d2);
    double det_z = a1 * (b2 * d3 - b3 * d2) - b1 * (a2 * d3 - a3 * d2) + d1 * (a2 * b3 - a3 * b2);
    
    double x = det_x / det;
    double y = det_y / det;
    double z = det_z / det;
    
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
    
    return 0;
}