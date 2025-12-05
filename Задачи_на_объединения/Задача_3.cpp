#include <iostream>
#include <string>
#include <iomanip>

union DateTimeUnion {
    struct {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    } components;
    
    long long timestamp;
};

class DateTime {
private:
    DateTimeUnion data;
    bool useComponents;
    
public:
    DateTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0) {
        setComponents(year, month, day, hour, minute, second);
    }
    
    DateTime(long long timestamp) {
        setTimestamp(timestamp);
    }
    
    void setComponents(int year, int month, int day, int hour, int minute, int second) {
        data.components.year = year;
        data.components.month = month;
        data.components.day = day;
        data.components.hour = hour;
        data.components.minute = minute;
        data.components.second = second;
        useComponents = true;
    }
    
    void setTimestamp(long long timestamp) {
        data.timestamp = timestamp;
        useComponents = false;
    }
    
    void getComponents(int& year, int& month, int& day, int& hour, int& minute, int& second) const {
        if (useComponents) {
            year = data.components.year;
            month = data.components.month;
            day = data.components.day;
            hour = data.components.hour;
            minute = data.components.minute;
            second = data.components.second;
        } else {
            year = 1970 + (data.timestamp / (365 * 24 * 3600));
            month = 1;
            day = 1;
            hour = 0;
            minute = 0;
            second = 0;
        }
    }
    
    long long getTimestamp() const {
        if (!useComponents) {
            return data.timestamp;
        } else {
            return (data.components.year - 1970) * 365 * 24 * 3600;
        }
    }
    
    void print() const {
        if (useComponents) {
            std::cout << std::setfill('0');
            std::cout << "Дата и время: " 
                      << std::setw(4) << data.components.year << "-"
                      << std::setw(2) << data.components.month << "-"
                      << std::setw(2) << data.components.day << " "
                      << std::setw(2) << data.components.hour << ":"
                      << std::setw(2) << data.components.minute << ":"
                      << std::setw(2) << data.components.second << std::endl;
        } else {
            std::cout << "Timestamp: " << data.timestamp << std::endl;
        }
    }
    
    void showMemoryUsage() const {
        std::cout << "\n=== Использование памяти ===" << std::endl;
        std::cout << "Размер структуры компонентов: " << sizeof(data.components) << " байт" << std::endl;
        std::cout << "Размер timestamp: " << sizeof(data.timestamp) << " байт" << std::endl;
        std::cout << "Размер объединения: " << sizeof(DateTimeUnion) << " байт" << std::endl;
        std::cout << "Размер класса DateTime: " << sizeof(DateTime) << " байт" << std::endl;
    }
};

int main() {
    int choice;
    
    do {
        std::cout << "\n=== Система хранения даты и времени ===" << std::endl;
        std::cout << "1. Установить дату и время (компоненты)" << std::endl;
        std::cout << "2. Установить timestamp" << std::endl;
        std::cout << "3. Показать текущие данные" << std::endl;
        std::cout << "4. Показать использование памяти" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        DateTime* dt = nullptr;
        
        switch (choice) {
            case 1: {
                int year, month, day, hour, minute, second;
                std::cout << "Введите год: ";
                std::cin >> year;
                std::cout << "Введите месяц: ";
                std::cin >> month;
                std::cout << "Введите день: ";
                std::cin >> day;
                std::cout << "Введите час: ";
                std::cin >> hour;
                std::cout << "Введите минуту: ";
                std::cin >> minute;
                std::cout << "Введите секунду: ";
                std::cin >> second;
                
                dt = new DateTime(year, month, day, hour, minute, second);
                dt->print();
                dt->showMemoryUsage();
                delete dt;
                break;
            }
            case 2: {
                long long timestamp;
                std::cout << "Введите timestamp: ";
                std::cin >> timestamp;
                
                dt = new DateTime(timestamp);
                dt->print();
                dt->showMemoryUsage();
                delete dt;
                break;
            }
            case 3: {
                DateTime current(2023, 11, 5, 14, 30, 45);
                current.print();
                current.showMemoryUsage();
                break;
            }
            case 4: {
                DateTime temp(0);
                temp.showMemoryUsage();
                break;
            }
            case 5:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор!" << std::endl;
        }
        
    } while (choice != 5);
    
    return 0;
}
