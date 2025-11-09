#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int* p = vec.data();
    
    for (size_t i = 0; i < vec.size(); i++) {
        *(p + i) += 10;
    }
    
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
