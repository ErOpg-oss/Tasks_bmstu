#include <iostream>

int main() {
    std::cout << "Программа выводит символы и их коды в таблице ASCII.Будут выведены все символы с кодами от 32 до 126 включительно."<< std::endl;

    for (int code = 32; code <= 126; ++code) {
        std::cout << code << " - " << char(code) << std::endl;
    }

    return 0;
}