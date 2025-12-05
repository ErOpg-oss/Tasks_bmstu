#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Product {
    int id;
    std::string name;
    std::string category;
    double price;
    int quantity;
};

int main() {
    std::ifstream f("products.csv");
    std::string line;
    std::getline(f, line); // Пропускаем заголовок
    
    std::vector<Product> products;
    
    while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string id_str, name, category, price_str, quantity_str;
        
        std::getline(ss, id_str, ',');
        std::getline(ss, name, ',');
        std::getline(ss, category, ',');
        std::getline(ss, price_str, ',');
        std::getline(ss, quantity_str, ',');
        
        products.push_back({
            std::stoi(id_str),
            name,
            category,
            std::stod(price_str),
            std::stoi(quantity_str)
        });
    }
    
    double total_value = 0;
    int total_quantity = 0;
    Product most_expensive = products[0];
    Product cheapest = products[0];
    
    for (auto &p : products) {
        total_value += p.price * p.quantity;
        total_quantity += p.quantity;
        
        if (p.price > most_expensive.price) most_expensive = p;
        if (p.price < cheapest.price) cheapest = p;
    }
    
    // Вывод всех товаров
    for (auto &p : products) {
        std::cout << p.id << ". " << p.name << " (" << p.category 
                  << ") - " << p.price << " руб., " << p.quantity << " шт.\n";
    }
    
    std::cout << "\n=== Статистика ===\n";
    std::cout << "Всего товаров на складе: " << total_quantity << " шт.\n";
    std::cout << "Суммарная стоимость: " << total_value << " руб.\n";
    std::cout << "Самый дорогой товар: " << most_expensive.name 
              << " (" << most_expensive.price << " руб.)\n";
    std::cout << "Самый дешевый товар: " << cheapest.name 
              << " (" << cheapest.price << " руб.)\n";
    
    return 0;
}
