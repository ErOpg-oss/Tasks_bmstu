#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

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
    
    // Запрос критерия сортировки у пользователя
    std::cout << "Выберите критерий сортировки:\n";
    std::cout << "1. По цене (возрастание)\n";
    std::cout << "2. По цене (убывание)\n";
    std::cout << "3. По названию (А-Я)\n";
    std::cout << "4. По количеству (убывание)\n";
    
    int choice;
    std::cin >> choice;
    
    // Лямбда-функции для сортировки
    switch (choice) {
        case 1:
            std::sort(products.begin(), products.end(), 
                     [](const Product& a, const Product& b) { return a.price < b.price; });
            break;
        case 2:
            std::sort(products.begin(), products.end(), 
                     [](const Product& a, const Product& b) { return a.price > b.price; });
            break;
        case 3:
            std::sort(products.begin(), products.end(), 
                     [](const Product& a, const Product& b) { return a.name < b.name; });
            break;
        case 4:
            std::sort(products.begin(), products.end(), 
                     [](const Product& a, const Product& b) { return a.quantity > b.quantity; });
            break;
        default:
            std::cout << "Неверный выбор. Сортировка по умолчанию (по цене возрастание).\n";
            std::sort(products.begin(), products.end(), 
                     [](const Product& a, const Product& b) { return a.price < b.price; });
    }
    
    // Сохранение отсортированных данных
    std::ofstream out("sorted_products.csv");
    out << "id,name,category,price,quantity\n";
    
    for (auto &p : products) {
        out << p.id << "," << p.name << "," << p.category 
            << "," << p.price << "," << p.quantity << "\n";
    }
    
    std::cout << "Данные отсортированы и сохранены в sorted_products.csv\n";
    return 0;
}
