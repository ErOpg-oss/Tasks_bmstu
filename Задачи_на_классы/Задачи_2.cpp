#include <iostream>
#include <string>

class Shape
{
protected:
    double length;
    
public:
    Shape(double len) : length(len) {}
    
    virtual void displayInfo() {
        std::cout << "Длина: " << length << std::endl;
    }
};

class Rectangle : public Shape
{
private:
    double width;

public:
    Rectangle(double len, double wid) : Shape(len), width(wid) {}

    double calculateArea() {
        return length * width;
    }

    double calculatePerimeter() {
        return 2 * (length + width);
    }

    void displayInfo() override {
        std::cout << "Длина: " << length 
                  << ", Ширина: " << width 
                  << ", Площадь: " << calculateArea()
                  << ", Периметр: " << calculatePerimeter() 
                  << std::endl;
    }
};

int main()
{
    Rectangle rect(5.5, 3.2);
    rect.displayInfo();
    return 0;
}