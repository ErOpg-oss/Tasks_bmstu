#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream f("book.txt");
    std::string word = "герой", line;
    int line_num = 0, total = 0;
    std::ofstream out("result.txt");
    
    while (std::getline(f, line)) {
        line_num++;
        size_t pos = line.find(word);
        
        while (pos != std::string::npos) {
            out << line_num << " " << pos << " " << word << "\n";
            total++;
            pos = line.find(word, pos + word.size());
        }
    }
    
    std::cout << "Всего: " << total;
    return 0;
}
