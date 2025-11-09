#include <iostream>

void swapPointers(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    int *p1 = &x, *p2 = &y;
    
    std::cout << "Before swap:" << std::endl;
    std::cout << "p1 points to: " << *p1 << " at address: " << p1 << std::endl;
    std::cout << "p2 points to: " << *p2 << " at address: " << p2 << std::endl;
    
    swapPointers(&p1, &p2);
    
    std::cout << "After swap:" << std::endl;
    std::cout << "p1 points to: " << *p1 << " at address: " << p1 << std::endl;
    std::cout << "p2 points to: " << *p2 << " at address: " << p2 << std::endl;
    
    return 0;
}
