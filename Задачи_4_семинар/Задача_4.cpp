#include <iostream>
#include <cmath>

int main() {
    std::cout << "Нахождение уравнения сферы по четырем точкам" << std::endl;
    
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
    
    std::cout << "Введите координаты точки A (x1 y1 z1): ";
    std::cin >> x1 >> y1 >> z1;
    
    std::cout << "Введите координаты точки B (x2 y2 z2): ";
    std::cin >> x2 >> y2 >> z2;
    
    std::cout << "Введите координаты точки C (x3 y3 z3): ";
    std::cin >> x3 >> y3 >> z3;
    
    std::cout << "Введите координаты точки D (x4 y4 z4): ";
    std::cin >> x4 >> y4 >> z4;
    
    double m11 = x1, m12 = y1, m13 = z1, m14 = 1;
    double m21 = x2, m22 = y2, m23 = z2, m24 = 1;
    double m31 = x3, m32 = y3, m33 = z3, m34 = 1;
    double m41 = x4, m42 = y4, m43 = z4, m44 = 1;
    
    double d1 = -(x1*x1 + y1*y1 + z1*z1);
    double d2 = -(x2*x2 + y2*y2 + z2*z2);
    double d3 = -(x3*x3 + y3*y3 + z3*z3);
    double d4 = -(x4*x4 + y4*y4 + z4*z4);
    
    double det = m11 * (m22*(m33*m44 - m34*m43) - m23*(m32*m44 - m34*m42) + m24*(m32*m43 - m33*m42))
               - m12 * (m21*(m33*m44 - m34*m43) - m23*(m31*m44 - m34*m41) + m24*(m31*m43 - m33*m41))
               + m13 * (m21*(m32*m44 - m34*m42) - m22*(m31*m44 - m34*m41) + m24*(m31*m42 - m32*m41))
               - m14 * (m21*(m32*m43 - m33*m42) - m22*(m31*m43 - m33*m41) + m23*(m31*m42 - m32*m41));
    
    double detA = d1 * (m22*(m33*m44 - m34*m43) - m23*(m32*m44 - m34*m42) + m24*(m32*m43 - m33*m42))
                - m12 * (d2*(m33*m44 - m34*m43) - m23*(d3*m44 - m34*d4) + m24*(d3*m43 - m33*d4))
                + m13 * (d2*(m32*m44 - m34*m42) - m22*(d3*m44 - m34*d4) + m24*(d3*m42 - m32*d4))
                - m14 * (d2*(m32*m43 - m33*m42) - m22*(d3*m43 - m33*d4) + m23*(d3*m42 - m32*d4));
    
    double detB = m11 * (d2*(m33*m44 - m34*m43) - m23*(d3*m44 - m34*d4) + m24*(d3*m43 - m33*d4))
                - d1 * (m21*(m33*m44 - m34*m43) - m23*(m31*m44 - m34*m41) + m24*(m31*m43 - m33*m41))
                + m13 * (m21*(d3*m44 - m34*d4) - d2*(m31*m44 - m34*m41) + m24*(m31*d4 - d3*m41))
                - m14 * (m21*(d3*m43 - m33*d4) - d2*(m31*m43 - m33*m41) + m23*(m31*d4 - d3*m41));
    
    double detC = m11 * (m22*(d3*m44 - m34*d4) - d2*(m32*m44 - m34*m42) + m24*(m32*d4 - d3*m42))
                - m12 * (m21*(d3*m44 - m34*d4) - d2*(m31*m44 - m34*m41) + m24*(m31*d4 - d3*m41))
                + d1 * (m21*(m32*m44 - m34*m42) - m22*(m31*m44 - m34*m41) + m24*(m31*m42 - m32*m41))
                - m14 * (m21*(m32*d4 - d3*m42) - m22*(m31*d4 - d3*m41) + d2*(m31*m42 - m32*m41));
    
    double detD = m11 * (m22*(m33*d4 - d3*m43) - m23*(m32*d4 - d3*m42) + d2*(m32*m43 - m33*m42))
                - m12 * (m21*(m33*d4 - d3*m43) - m23*(m31*d4 - d3*m41) + d2*(m31*m43 - m33*m41))
                + m13 * (m21*(m32*d4 - d3*m42) - m22*(m31*d4 - d3*m41) + d2*(m31*m42 - m32*m41))
                - d1 * (m21*(m32*m43 - m33*m42) - m22*(m31*m43 - m33*m41) + m23*(m31*m42 - m32*m41));
    
    double A = detA / det;
    double B = detB / det;
    double C = detC / det;
    double D = detD / det;
    
    double x0 = -A / 2;
    double y0 = -B / 2;
    double z0 = -C / 2;
    double r = sqrt(x0*x0 + y0*y0 + z0*z0 - D);
    
    std::cout << "Уравнение сферы: x² + y² + z² + " << A << "x + " << B << "y + " << C << "z + " << D << " = 0" << std::endl;
    std::cout << "Центр сферы: (" << x0 << ", " << y0 << ", " << z0 << ")" << std::endl;
    std::cout << "Радиус сферы: " << r << std::endl;
    
    return 0;
}