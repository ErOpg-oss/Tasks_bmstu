#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
    int id;
    char name[50];
    int age;
    double avg;
};

int main() {
    Student s[] = {
        {1, "Иван", 20, 4.5},
        {2, "Мария", 19, 4.8},
        {3, "Алексей", 21, 4.2}
    };
    
    {
        std::ofstream f("students.dat", std::ios::binary);
        for (auto &x : s) {
            f.write((char*)&x, sizeof(Student));
        }
    }
    
    std::ifstream f("students.dat", std::ios::binary);
    Student t;
    Student best = s[0];
    int count = 0;
    
    while (f.read((char*)&t, sizeof(Student))) {
        std::cout << t.id << " " << t.name << " " << t.avg << "\n";
        if (t.avg > best.avg) best = t;
        count++;
    }
    
    std::cout << "Всего = " << count << " Лучший = " << best.name;
    return 0;
}
