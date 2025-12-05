#include <iostream>
#include <fstream>

int main() {
    int a[10] = {15, 23, 7, 42, 18, 91, 3, 56, 77, 10};
    int b[10];
    
    {
        std::ofstream f("numbers.bin", std::ios::binary);
        f.write((char*)a, sizeof(a));
    }
    
    std::ifstream f("numbers.bin", std::ios::binary);
    f.read((char*)b, sizeof(b));
    f.seekg(0, std::ios::end);
    
    std::cout << "Размер: " << f.tellg() << "\n";
    
    int sum = 0;
    for (int x : b) {
        std::cout << x << " ";
        sum += x;
    }
    
    std::cout << "\nСумма = " << sum;
    return 0;
}
