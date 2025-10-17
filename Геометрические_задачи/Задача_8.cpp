#include <iostream>
#include <cmath>

double length(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1; 
    int dy = y2 - y1; 
    return sqrt(dx * dx + dy * dy); 
}

int main(){
    int x1, y1, x2, y2;
    std::cout << "Введите координаты двух точек x y:\n";
    std::cout << "Первая точка: ";
    std::cin >> x1 >> y1;
    std::cout << "Вторая точка: ";
    std::cin >> x2 >> y2;
    std::cout << "Длина: " << length(x1, y1, x2, y2);
    return 0;
}