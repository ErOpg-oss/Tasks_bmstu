#include <iostream>
#include <string>

class Publication
{
protected:
    std::string title;
    
public:
    Publication(const std::string& title) : title(title) {}
};

class Book : public Publication
{
private:
    std::string author;
    size_t year;

public:
    Book(const std::string& title, const std::string& author, size_t year)
        : Publication(title), author(author), year(year) {}

    void displayInfo() {
        std::cout << "Название: " << title 
                  << ", Автор: " << author 
                  << ", Год выпуска: " << year 
                  << std::endl;
    }
};

int main()
{
    Book myBook("Как стать программистом за один вечер", "Kutsepalov Egor", 2024);
    myBook.displayInfo();
    return 0;
}