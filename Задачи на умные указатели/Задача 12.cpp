#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> logs = {
        "INFO: Start",
        "ERROR: Disk failure",
        "WARNING: Low memory",
        "ERROR: Disk failure",
        "INFO: Stop"
    };
    
    auto pLogs = std::make_shared<std::vector<std::string>>(logs);
    
    std::vector<std::string> errors;
    
    auto filterErrors = [](std::shared_ptr<std::vector<std::string>> logs) {
        std::vector<std::string> result;
        for (const auto& log : *logs) {
            if (log.find("ERROR:") != std::string::npos) {
                result.push_back(log);
            }
        }
        return result;
    };
    
    auto removeDuplicates = [](std::vector<std::string>& vec) {
        std::sort(vec.begin(), vec.end());
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    };
    
    errors = filterErrors(pLogs);
    removeDuplicates(errors);
    
    std::cout<<"Все логи:"<<std::endl;
    for (const auto& log : *pLogs) {
        std::cout<<log<<std::endl;
    }
    
    std::cout<<"\nУникальные ошибки:"<<std::endl;
    for (const auto& error : errors) {
        std::cout<<error<<std::endl;
    }
    
    return 0;
}