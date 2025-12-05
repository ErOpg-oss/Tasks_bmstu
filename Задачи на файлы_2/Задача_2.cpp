#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::fstream f("config.txt");
    std::vector<char> buf((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    std::string s(buf.begin(), buf.end());
    
    std::string key = "timeout=";
    size_t p = s.find(key);
    
    if (p != std::string::npos) {
        size_t e = s.find('\n', p);
        s.replace(p + key.size(), e - (p + key.size()), "60");
    }
    
    std::ofstream o("config.txt");
    o << s;
    return 0;
}
