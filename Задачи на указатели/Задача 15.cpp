#include <iostream>
#include <vector>
#include <string>

struct Command {
    std::string name;
    int value;
};

void parseCommand(const char* input, std::vector<Command>& buffer) {
    const char* p = input;
    std::string name;
    int value = 0;
    
    while (*p != ' ' && *p != '\0') {
        name += *p;
        p++;
    }
    
    if (*p == ' ') {
        p++;
        value = std::stoi(std::string(p));
    }
    
    buffer.push_back({name, value});
}

int main() {
    std::vector<Command> buffer;
    parseCommand("FORWARD 10", buffer);
    parseCommand("TURN 90", buffer);
    parseCommand("STOP", buffer);
    
    for (const auto& cmd : buffer) {
        std::cout << "Command: " << cmd.name << ", Value: " << cmd.value << std::endl;
    }
    
    return 0;
}
