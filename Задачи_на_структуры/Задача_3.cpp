#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    int year;
    std::string genre;
};

class Library {
private:
    std::vector<Book> books;
    
public:
    void addBook() {
        Book newBook;
        
        std::cout << "Введите название книги: ";
        std::cin.ignore();
        std::getline(std::cin, newBook.title);
        
        std::cout << "Введите автора книги: ";
        std::getline(std::cin, newBook.author);
        
        std::cout << "Введите год издания: ";
        std::cin >> newBook.year;
        
        std::cout << "Введите жанр книги: ";
        std::cin.ignore();
        std::getline(std::cin, newBook.genre);
        
        books.push_back(newBook);
        std::cout << "Книга добавлена успешно!" << std::endl;
    }
    
    void removeBook() {
        std::string title;
        
        std::cout << "Введите название книги для удаления: ";
        std::cin.ignore();
        std::getline(std::cin, title);
        
        auto it = std::remove_if(books.begin(), books.end(),
            [&title](const Book& book) {
                return book.title == title;
            });
        
        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "Книга удалена успешно!" << std::endl;
        } else {
            std::cout << "Книга с таким названием не найдена!" << std::endl;
        }
    }
    
    void searchByAuthor() {
        std::string author;
        
        std::cout << "Введите автора для поиска: ";
        std::cin.ignore();
        std::getline(std::cin, author);
        
        std::cout << "\n=== Книги автора " << author << " ===" << std::endl;
        bool found = false;
        
        for (const auto& book : books) {
            if (book.author == author) {
                std::cout << "Название: " << book.title 
                          << ", Год: " << book.year 
                          << ", Жанр: " << book.genre << std::endl;
                found = true;
            }
        }
        
        if (!found) {
            std::cout << "Книги данного автора не найдены." << std::endl;
        }
    }
    
    void showAllBooks() {
        if (books.empty()) {
            std::cout << "Библиотека пуста." << std::endl;
            return;
        }
        
        std::cout << "\n=== Все книги в библиотеке ===" << std::endl;
        for (size_t i = 0; i < books.size(); ++i) {
            std::cout << (i + 1) << ". " << books[i].title 
                      << " (" << books[i].author << ", " 
                      << books[i].year << ", " << books[i].genre << ")" << std::endl;
        }
    }
    
    void showMenu() {
        int choice;
        
        do {
            std::cout << "\n=== Система управления библиотекой ===" << std::endl;
            std::cout << "1. Добавить новую книгу" << std::endl;
            std::cout << "2. Удалить книгу по названию" << std::endl;
            std::cout << "3. Найти книги по автору" << std::endl;
            std::cout << "4. Показать все книги" << std::endl;
            std::cout << "5. Выйти" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    removeBook();
                    break;
                case 3:
                    searchByAuthor();
                    break;
                case 4:
                    showAllBooks();
                    break;
                case 5:
                    std::cout << "Выход из программы." << std::endl;
                    break;
                default:
                    std::cout << "Неверный выбор!" << std::endl;
            }
        } while (choice != 5);
    }
};

int main() {
    Library library;
    library.showMenu();
    return 0;
}
