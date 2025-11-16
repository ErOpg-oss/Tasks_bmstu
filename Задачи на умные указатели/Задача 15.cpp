#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    auto route1 = std::make_unique<std::string>("Paris-Rome");
    auto route2 = std::make_unique<std::string>("Berlin-Paris");
    auto route3 = std::make_unique<std::string>("Moscow-Berlin");
    auto route4 = std::make_unique<std::string>("Rome-Moscow");

    std::vector<std::unique_ptr<std::string>> routes;
    routes.push_back(std::move(route1));
    routes.push_back(std::move(route2));
    routes.push_back(std::move(route3));
    routes.push_back(std::move(route4));

    auto countParis = [](const std::vector<std::unique_ptr<std::string>>& routes) {
        int count = 0;
        for (const auto& route : routes) {
            if (route->find("Paris") != std::string::npos) {
                count++;
            }
        }
        return count;
    };

    auto sortRoutes = [](std::vector<std::unique_ptr<std::string>>& routes) {
        std::sort(routes.begin(), routes.end(),
            [](const std::unique_ptr<std::string>& a, const std::unique_ptr<std::string>& b) {
                return *a < *b;
            });
    };

    auto joinRoutes = [](const std::vector<std::unique_ptr<std::string>>& routes) {
        std::string result;
        for (size_t i = 0; i < routes.size(); ++i) {
            result += *routes[i];
            if (i < routes.size() - 1) {
                result += " -> ";
            }
        }
        return result;
    };

    int parisCount = countParis(routes);
    std::cout<<"Количество маршрутов с \"Paris\": "<<parisCount<<std::endl;

    sortRoutes(routes);
    std::cout<<"Отсортированные маршруты:"<<std::endl;
    for (const auto& route : routes) {
        std::cout<<*route<<std::endl;
    }

    std::string fullRoute = joinRoutes(routes);
    std::cout<<"Общий маршрут:"<<std::endl;
    std::cout<<fullRoute<<std::endl;

    return 0;
}