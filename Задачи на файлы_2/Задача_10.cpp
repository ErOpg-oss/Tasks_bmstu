#include <iostream>
#include <fstream>
#include <string>

void createConfig() {
    std::ofstream file("config.json");
    file << "{\n";
    file << "  \"app_name\": \"My Application\",\n";
    file << "  \"version\": \"1.0.0\",\n";
    file << "  \"settings\": {\n";
    file << "    \"max_connections\": 100,\n";
    file << "    \"timeout\": 30,\n";
    file << "    \"debug_mode\": true\n";
    file << "  },\n";
    file << "  \"database\": {\n";
    file << "    \"host\": \"localhost\",\n";
    file << "    \"port\": 5432,\n";
    file << "    \"username\": \"admin\"\n";
    file << "  }\n";
    file << "}";
    file.close();
    std::cout << "Конфигурационный файл создан\n";
}

void readAndModifyConfig() {
    // Чтение файла
    std::ifstream r("config.json");
    std::string content((std::istreambuf_iterator<char>(r)), 
                        std::istreambuf_iterator<char>());
    r.close();
    
    std::cout << "Текущий конфиг:\n" << content << "\n\n";
    
    // Изменение значения timeout
    size_t pos = content.find("\"timeout\": 30");
    if (pos != std::string::npos) {
        content.replace(pos + 11, 2, "60");
        std::cout << "Изменен timeout с 30 на 60\n";
    }
    
    // Сохранение обратно
    std::ofstream w("config.json");
    w << content;
    w.close();
    
    std::cout << "Конфиг обновлен\n";
}

int main() {
    createConfig();
    readAndModifyConfig();
    return 0;
}
