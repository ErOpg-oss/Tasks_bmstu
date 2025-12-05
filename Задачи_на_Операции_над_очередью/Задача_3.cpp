#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Order {
    std::string customerName;
    std::vector<std::string> items;
};

void addOrder(std::queue<Order>& orderQueue, const Order& newOrder) {
    orderQueue.push(newOrder);
    std::cout << "Заказ добавлен для клиента: " << newOrder.customerName << std::endl;
}

void processOrder(std::queue<Order>& orderQueue) {
    if (!orderQueue.empty()) {
        Order currentOrder = orderQueue.front();
        orderQueue.pop();
        
        std::cout << "\n=== Обработка заказа ===" << std::endl;
        std::cout << "Клиент: " << currentOrder.customerName << std::endl;
        std::cout << "Товары:" << std::endl;
        
        for (size_t i = 0; i < currentOrder.items.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << currentOrder.items[i] << std::endl;
        }
        
        std::cout << "Заказ обработан успешно!" << std::endl;
    } else {
        std::cout << "Очередь заказов пуста." << std::endl;
    }
}

int main() {
    std::queue<Order> orders;
    
    Order order1 = {
        "Иван Иванов",
        {"Ноутбук Dell", "Мышь беспроводная", "Сумка для ноутбука"}
    };
    
    Order order2 = {
        "Мария Петрова",
        {"Смартфон Samsung", "Чехол", "Защитное стекло"}
    };
    
    Order order3 = {
        "Алексей Сидоров",
        {"Наушники Sony", "Кабель USB-C"}
    };
    
    addOrder(orders, order1);
    addOrder(orders, order2);
    addOrder(orders, order3);
    
    std::cout << "\nОбработка заказов:" << std::endl;
    processOrder(orders);
    processOrder(orders);
    processOrder(orders);
    processOrder(orders);
    
    return 0;
}
