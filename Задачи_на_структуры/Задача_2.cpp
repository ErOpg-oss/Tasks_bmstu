#include <iostream>
#include <string>
#include <vector>

struct BankAccount {
    int accountNumber;
    std::string accountHolder;
    double balance;
};

class BankSystem {
private:
    std::vector<BankAccount> accounts;
    
    int findAccountIndex(int accountNumber) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i].accountNumber == accountNumber) {
                return i;
            }
        }
        return -1;
    }
    
public:
    void createAccount() {
        BankAccount newAccount;
        
        std::cout << "Введите номер счета: ";
        std::cin >> newAccount.accountNumber;
        
        std::cout << "Введите имя владельца счета: ";
        std::cin.ignore();
        std::getline(std::cin, newAccount.accountHolder);
        
        newAccount.balance = 0.0;
        accounts.push_back(newAccount);
        
        std::cout << "Банковский счет создан успешно!" << std::endl;
    }
    
    void deposit() {
        int accountNumber;
        double amount;
        
        std::cout << "Введите номер счета для пополнения: ";
        std::cin >> accountNumber;
        
        int index = findAccountIndex(accountNumber);
        if (index == -1) {
            std::cout << "Счет не найден!" << std::endl;
            return;
        }
        
        std::cout << "Введите сумму для пополнения: ";
        std::cin >> amount;
        
        if (amount > 0) {
            accounts[index].balance += amount;
            std::cout << "Счет пополнен на " << amount << " рублей." << std::endl;
        } else {
            std::cout << "Некорректная сумма!" << std::endl;
        }
    }
    
    void withdraw() {
        int accountNumber;
        double amount;
        
        std::cout << "Введите номер счета для снятия: ";
        std::cin >> accountNumber;
        
        int index = findAccountIndex(accountNumber);
        if (index == -1) {
            std::cout << "Счет не найден!" << std::endl;
            return;
        }
        
        std::cout << "Введите сумму для снятия: ";
        std::cin >> amount;
        
        if (amount > 0 && amount <= accounts[index].balance) {
            accounts[index].balance -= amount;
            std::cout << "Со счета снято " << amount << " рублей." << std::endl;
        } else {
            std::cout << "Недостаточно средств или некорректная сумма!" << std::endl;
        }
    }
    
    void showAccountInfo() {
        int accountNumber;
        
        std::cout << "Введите номер счета для показа информации: ";
        std::cin >> accountNumber;
        
        int index = findAccountIndex(accountNumber);
        if (index == -1) {
            std::cout << "Счет не найден!" << std::endl;
            return;
        }
        
        std::cout << "\n=== Информация о счете ===" << std::endl;
        std::cout << "Номер счета: " << accounts[index].accountNumber << std::endl;
        std::cout << "Владелец счета: " << accounts[index].accountHolder << std::endl;
        std::cout << "Баланс: " << accounts[index].balance << " рублей" << std::endl;
    }
    
    void showMenu() {
        int choice;
        
        do {
            std::cout << "\n=== Банковская система ===" << std::endl;
            std::cout << "1. Создать новый банковский счет" << std::endl;
            std::cout << "2. Положить деньги на счет" << std::endl;
            std::cout << "3. Снять деньги со счета" << std::endl;
            std::cout << "4. Показать информацию о счете" << std::endl;
            std::cout << "5. Выйти" << std::endl;
            std::cout << "Выберите действие: ";
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    showAccountInfo();
                    break;
                case 5:
                    std::cout << "Программа завершена." << std::endl;
                    break;
                default:
                    std::cout << "Неверный выбор!" << std::endl;
            }
        } while (choice != 5);
    }
};

int main() {
    BankSystem bank;
    bank.showMenu();
    return 0;
}
