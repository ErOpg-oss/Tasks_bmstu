#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream f("application.log");
    std::string line; 
    int part = 1, lines = 0;
    std::ofstream cur("log_part1.txt");
    
    while (std::getline(f, line)) {
        if (lines == 1000) {
            cur.close(); 
            cur.open("log_part" + std::to_string(++part) + ".txt"); 
            lines = 0;
        }
        
        cur << line << "\n";
        lines++;
    }
    
    cur.close();
    
    std::ofstream idx("index.txt");
    for (int i = 1; i <= part; i++) {
        idx << "log_part" << i << ".txt\n";
    }
    
    return 0;
}
