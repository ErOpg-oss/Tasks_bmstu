#include <iostream>
#include <string>
#include <vector>
#include <limits>

struct Employee {
    std::string name;
    int age;
    std::string position;
    double salary;
};

void inputEmployee(Employee& emp) {
    std::cout << "Введите имя сотрудника: ";
    std::cin.ignore();
    std::getline(std::cin, emp.name);
    
    std::cout << "Введите возраст сотрудника: ";
    std::cin >> emp.age;
    
    std::cout << "Введите должность сотрудника: ";
    std::cin.ignore();
    std::getline(std::cin, emp.position);
    
    std::cout << "Введите зарплату сотрудника: ";
    std::cin >> emp.salary;
}

void printEmployee(const Employee& emp) {
    std::cout << "Имя: " << emp.name 
              << ", Возраст: " << emp.age 
              << ", Должность: " << emp.position 
              << ", Зарплата: " << emp.salary << std::endl;
}

int main() {
    int n;
    std::cout << "Введите количество сотрудников: ";
    std::cin >> n;
    
    std::vector<Employee> employees(n);
    
    for (int i = 0; i < n; ++i) {
        std::cout << "\n=== Сотрудник " << (i + 1) << " ===" << std::endl;
        inputEmployee(employees[i]);
    }
    
    int youngestIndex = 0;
    int oldestIndex = 0;
    double totalSalary = 0;
    
    for (int i = 0; i < n; ++i) {
        if (employees[i].age < employees[youngestIndex].age) {
            youngestIndex = i;
        }
        if (employees[i].age > employees[oldestIndex].age) {
            oldestIndex = i;
        }
        totalSalary += employees[i].salary;
    }
    
    std::cout << "\n=== Результаты ===" << std::endl;
    std::cout << "Самый молодой сотрудник: ";
    printEmployee(employees[youngestIndex]);
    
    std::cout << "Самый старший сотрудник: ";
    printEmployee(employees[oldestIndex]);
    
    std::cout << "Средняя зарплата всех сотрудников: " 
              << (totalSalary / n) << std::endl;
    
    return 0;
}
