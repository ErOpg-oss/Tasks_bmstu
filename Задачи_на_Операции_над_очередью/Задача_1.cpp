#include <iostream>
#include <queue>
#include <string>

void addToQueue(std::queue<std::string>& queue, const std::string& person) {
    queue.push(person);
    std::cout << person << " добавлен в очередь." << std::endl;
}

void processQueue(std::queue<std::string>& queue) {
    if (!queue.empty()) {
        std::string person = queue.front();
        queue.pop();
        std::cout << person << " обработан и удален из очереди." << std::endl;
    } else {
        std::cout << "Очередь пуста." << std::endl;
    }
}

int main() {
    std::queue<std::string> supermarketQueue;
    
    addToQueue(supermarketQueue, "Иван Петров");
    addToQueue(supermarketQueue, "Мария Сидорова");
    addToQueue(supermarketQueue, "Алексей Иванов");
    
    std::cout << "\nОбработка очереди:" << std::endl;
    processQueue(supermarketQueue);
    processQueue(supermarketQueue);
    processQueue(supermarketQueue);
    processQueue(supermarketQueue);
    
    return 0;
}
