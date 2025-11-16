#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);
    
    std::unique_ptr<int> ptr2 = std::move(ptr1);
    
    if (ptr1 == nullptr) {
        std::cout<<"ptr1 теперь nullptr"<<std::endl;
    } else {
        std::cout<<"ptr1 не nullptr"<<std::endl;
    }
    
    std::cout<<"ptr2 содержит: "<<*ptr2<<std::endl;
    
    return 0;
}