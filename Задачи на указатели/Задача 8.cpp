#include <iostream>

const char* findSubstring(const char* text, const char* word) {
    const char* textPtr = text;
    const char* wordPtr = word;
    
    while (*textPtr != '\0') {
        const char* tempText = textPtr;
        wordPtr = word;
        
        while (*wordPtr != '\0' && *tempText == *wordPtr) {
            tempText++;
            wordPtr++;
        }
        
        if (*wordPtr == '\0') return textPtr;
        textPtr++;
    }
    
    return nullptr;
}

int main() {
    const char* text = "hello world";
    const char* word = "world";
    const char* result = findSubstring(text, word);
    
    if (result) std::cout << result << std::endl;
    else std::cout << "Not found" << std::endl;
    
    return 0;
}
