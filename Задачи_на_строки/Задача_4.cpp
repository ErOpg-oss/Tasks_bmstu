#include <iostream>
#include <cstring>

int main() {
    char A[100], B[100];
    
    std::cout << "Введите строку A: ";
    std::cin.getline(A, 100);
    std::cout << "Введите строку B: ";
    std::cin.getline(B, 100);
    
    bool allFound = true;
    
    for (int i = 0; B[i] != '\0'; i++) {
        bool found = false;
        for (int j = 0; A[j] != '\0'; j++) {
            if (A[j] == B[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            allFound = false;
            break;
        }
    }
    
    if (allFound) std::cout << "Да" << std::endl;
    else std::cout << "Нет" << std::endl;
    
    return 0;
}
