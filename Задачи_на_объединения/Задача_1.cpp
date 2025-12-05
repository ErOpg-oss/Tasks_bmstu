#include <iostream>
#include <cstring>

union Variant {
    int intValue;
    double doubleValue;
    char charValue;
};

enum DataType { INT, DOUBLE, CHAR };

struct TypedVariant {
    Variant data;
    DataType type;
};

void setValue(TypedVariant& variant, int value) {
    variant.data.intValue = value;
    variant.type = INT;
}

void setValue(TypedVariant& variant, double value) {
    variant.data.doubleValue = value;
    variant.type = DOUBLE;
}

void setValue(TypedVariant& variant, char value) {
    variant.data.charValue = value;
    variant.type = CHAR;
}

void printValue(const TypedVariant& variant) {
    switch (variant.type) {
        case INT:
            std::cout << "Целое число: " << variant.data.intValue << std::endl;
            break;
        case DOUBLE:
            std::cout << "Число с плавающей запятой: " << variant.data.doubleValue << std::endl;
            break;
        case CHAR:
            std::cout << "Символ: '" << variant.data.charValue << "'" << std::endl;
            break;
        default:
            std::cout << "Неизвестный тип данных!" << std::endl;
    }
}

int main() {
    TypedVariant var;
    char choice;
    
    std::cout << "Выберите тип данных (i - целое число, d - число с плавающей запятой, c - символ): ";
    std::cin >> choice;
    
    switch (choice) {
        case 'i': {
            int value;
            std::cout << "Введите целое число: ";
            std::cin >> value;
            setValue(var, value);
            break;
        }
        case 'd': {
            double value;
            std::cout << "Введите число с плавающей запятой: ";
            std::cin >> value;
            setValue(var, value);
            break;
        }
        case 'c': {
            char value;
            std::cout << "Введите символ: ";
            std::cin >> value;
            setValue(var, value);
            break;
        }
        default:
            std::cout << "Неверный выбор!" << std::endl;
            return 1;
    }
    
    std::cout << "\nВведенное значение: ";
    printValue(var);
    
    std::cout << "\n=== Размеры в памяти ===" << std::endl;
    std::cout << "Размер int: " << sizeof(int) << " байт" << std::endl;
    std::cout << "Размер double: " << sizeof(double) << " байт" << std::endl;
    std::cout << "Размер char: " << sizeof(char) << " байт" << std::endl;
    std::cout << "Размер объединения Variant: " << sizeof(Variant) << " байт" << std::endl;
    std::cout << "Размер структуры TypedVariant: " << sizeof(TypedVariant) << " байт" << std::endl;
    
    return 0;
}
