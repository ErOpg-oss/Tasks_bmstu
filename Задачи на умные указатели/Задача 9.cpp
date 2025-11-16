#include <iostream>
#include <memory>
#include <vector>

void processA(std::shared_ptr<std::vector<int>> buf) {
    for (auto& num : *buf) {
        num += 1;
    }
}

void processB(std::shared_ptr<std::vector<int>> buf) {
    for (auto& num : *buf) {
        num *= 2;
    }
}

int main() {
    auto buffer = std::make_shared<std::vector<int>>();
    
    for (int i = 1; i <= 10; ++i) {
        buffer->push_back(i);
    }
    
    std::cout<<"Исходный: ";
    for (auto num : *buffer) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    
    processA(buffer);
    std::cout<<"После processA: ";
    for (auto num : *buffer) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    
    processB(buffer);
    std::cout<<"После processB: ";
    for (auto num : *buffer) {
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}