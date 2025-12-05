#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>

void addEvent(std::queue<std::string>& eventQueue, const std::string& event) {
    eventQueue.push(event);
    std::cout << "Событие добавлено: " << event << std::endl;
}

void processEvents(std::queue<std::string>& eventQueue) {
    if (!eventQueue.empty()) {
        while (!eventQueue.empty()) {
            std::string event = eventQueue.front();
            eventQueue.pop();
            std::cout << "Обработка события: " << event << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::cout << "Все события обработаны." << std::endl;
    } else {
        std::cout << "Очередь событий пуста." << std::endl;
    }
}

int main() {
    std::queue<std::string> networkEvents;
    
    addEvent(networkEvents, "Запрос от клиента A: GET /api/data");
    addEvent(networkEvents, "Запрос от клиента B: POST /api/login");
    addEvent(networkEvents, "Запрос от клиента C: PUT /api/update");
    addEvent(networkEvents, "Запрос от клиента D: DELETE /api/resource");
    
    std::cout << "\nНачало обработки событий..." << std::endl;
    processEvents(networkEvents);
    processEvents(networkEvents);
    
    return 0;
}
