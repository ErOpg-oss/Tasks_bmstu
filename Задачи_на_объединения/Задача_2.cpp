#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

struct Circle {
    double radius;
};

struct Rectangle {
    double length;
    double width;
};

union ShapeData {
    Circle circle;
    Rectangle rectangle;
};

enum ShapeType { CIRCLE, RECTANGLE };

struct Shape {
    ShapeData data;
    ShapeType type;
};

double calculateArea(const Circle& circle) {
    return PI * circle.radius * circle.radius;
}

double calculateArea(const Rectangle& rectangle) {
    return rectangle.length * rectangle.width;
}

double calculateArea(const Shape& shape) {
    switch (shape.type) {
        case CIRCLE:
            return calculateArea(shape.data.circle);
        case RECTANGLE:
            return calculateArea(shape.data.rectangle);
        default:
            return 0.0;
    }
}

void setCircle(Shape& shape, double radius) {
    shape.data.circle.radius = radius;
    shape.type = CIRCLE;
}

void setRectangle(Shape& shape, double length, double width) {
    shape.data.rectangle.length = length;
    shape.data.rectangle.width = width;
    shape.type = RECTANGLE;
}

int main() {
    Shape shape;
    int choice;
    
    do {
        std::cout << "\n=== Управление геометрическими фигурами ===" << std::endl;
        std::cout << "1. Круг" << std::endl;
        std::cout << "2. Прямоугольник" << std::endl;
        std::cout << "3. Выход" << std::endl;
        std::cout << "Выберите фигуру: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                double radius;
                std::cout << "Введите радиус круга: ";
                std::cin >> radius;
                setCircle(shape, radius);
                std::cout << "Площадь круга: " << calculateArea(shape) << std::endl;
                break;
            }
            case 2: {
                double length, width;
                std::cout << "Введите длину прямоугольника: ";
                std::cin >> length;
                std::cout << "Введите ширину прямоугольника: ";
                std::cin >> width;
                setRectangle(shape, length, width);
                std::cout << "Площадь прямоугольника: " << calculateArea(shape) << std::endl;
                break;
            }
            case 3:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор!" << std::endl;
        }
        
        if (choice != 3) {
            std::cout << "\nРазмер структуры Circle: " << sizeof(Circle) << " байт" << std::endl;
            std::cout << "Размер структуры Rectangle: " << sizeof(Rectangle) << " байт" << std::endl;
            std::cout << "Размер объединения ShapeData: " << sizeof(ShapeData) << " байт" << std::endl;
            std::cout << "Размер структуры Shape: " << sizeof(Shape) << " байт" << std::endl;
        }
        
    } while (choice != 3);
    
    return 0;
}
