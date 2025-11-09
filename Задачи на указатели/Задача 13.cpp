#include <iostream>

void parseTelemetry(const char* data) {
    const char* p = data;
    
    while (*p != '\0') {
        const char* name_start = p;
        
        while (*p != ':' && *p != '\0') p++;
        if (*p == '\0') break;
        
        const char* value_start = p + 1;
        
        while (*p != ';' && *p != '\0') p++;
        
        std::cout << std::string(name_start, value_start - 1) << ": " 
                  << std::string(value_start, p) << std::endl;
        
        if (*p == ';') p++;
    }
}

int main() {
    const char* data = "TEMP:24.5;PRESS:101.3;HUM:55.2";
    parseTelemetry(data);
    return 0;
}
