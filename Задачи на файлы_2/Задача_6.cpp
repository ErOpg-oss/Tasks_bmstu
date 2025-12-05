#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream f("products.csv");
    f << "id,name,category,price,quantity\n";
    std::srand(std::time(nullptr));
    
    for (int i = 1; i <= 20; i++) {
        f << i << ",Prod" << i << ",Cat" << (i % 3) << "," 
          << (100 + rand() % 9901) << "," << (1 + rand() % 100) << "\n";
    }
    
    return 0;
}
