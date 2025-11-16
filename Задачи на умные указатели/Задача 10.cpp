#include <iostream>
#include <memory>

std::unique_ptr<int[]> createArray(int n) {
    auto arr = std::make_unique<int[]>(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int n = 5;
    auto arr = createArray(n);
    
    for (int i = 0; i < n; ++i) {
        std::cout<<arr[i]<<" ";
    }
    
    return 0;
}