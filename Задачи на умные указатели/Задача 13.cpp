#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main() {
    std::unique_ptr<std::string> part1 = std::make_unique<std::string>("Sensor data:");
    std::unique_ptr<std::string> part2 = std::make_unique<std::string>("Voltage stable.");
    std::unique_ptr<std::string> part3 = std::make_unique<std::string>("System nominal.");
    
    std::vector<std::unique_ptr<std::string>> reportParts;
    reportParts.push_back(std::move(part1));
    reportParts.push_back(std::move(part2));
    reportParts.push_back(std::move(part3));
    
    auto concatParts = [](std::vector<std::unique_ptr<std::string>>& parts) {
        std::string result;
        for (const auto& part : parts) {
            result += *part + "\n";
        }
        return result;
    };
    
    auto countWord = [](const std::string& text, const std::string& word) {
        int count = 0;
        size_t pos = 0;
        while ((pos = text.find(word, pos)) != std::string::npos) {
            count++;
            pos += word.length();
        }
        return count;
    };
    
    std::string report = concatParts(reportParts);
    int wordCount = countWord(report, "data");
    
    std::cout<<"Отчёт:"<<std::endl;
    std::cout<<report;
    std::cout<<"Слово \"data\" встречается "<<wordCount<<" раз"<<std::endl;
    
    return 0;
}