#include <iostream>
#include <cmath>


double centreX(double dot[3][2]) {

    double x1 = dot[0][0];
    double x2 = dot[1][0];
    double x3 = dot[2][0];
    
    return (x1+x2+x3)/3;
    
}

double centreY(double dot[3][2]) {

    double y1 = dot[0][1];
    double y2 = dot[1][1];
    double y3 = dot[2][1];
    
    return (y1+y2+y3)/3;
    
}

int main() {
    double dot[3][2];

    std::cout << "Нахождение центра масс треугольника. Введите координаты трех точек x y" <<std::endl;
    for (int i = 0; i < 3; i++) std::cin >> dot[i][0] >> dot[i][1];

    
    std::cout <<"Координаты центра масс треугольника ("<<centreX(dot)<<"; "<<centreY(dot)<<")"<<std::endl;

    return 0;
}