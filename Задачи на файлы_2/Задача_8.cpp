#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

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
    
    // Лямбда-функции для фильтрации
    auto expensive_filter = [](const Product& p) { return p.price > 5000; };
    auto electronics_filter = [](const Product& p) { return p.category == "Электроника"; };
    auto in_stock_filter = [](const Product& p) { return p.quantity > 10; };
    
    // Фильтрация по цене > 5000
    std::vector<Product> filtered_products;
    std::copy_if(products.begin(), products.end(), 
                 std::back_inserter(filtered_products), expensive_filter);
    
    // Сохранение отфильтрованных данных
    std::ofstream out("filtered_products.csv");
    out << "id,name,category,price,quantity\n";
    
    for (auto &p : filtered_products) {
        out << p.id << "," << p.name << "," << p.category 
            << "," << p.price << "," << p.quantity << "\n";
    }
    
    std::cout << "Отфильтровано товаров: " << filtered_products.size() << "\n";
    return 0;
}
