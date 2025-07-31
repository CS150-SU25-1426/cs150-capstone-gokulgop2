#include <iostream>
#include <limits>
#include "BookList.h"
#include "UsedBook.h"

void displayMenu();
int getMenuChoice();

int main() {
    BookList inventory;
    int choice = 0;

    // data
    inventory.addBook(std::make_unique<Book>("The Hitchhiker's Guide", "Douglas Adams", "978-0345391803", 42));
    inventory.addBook(std::make_unique<UsedBook>("Dune", "Frank Herbert", "978-0441013593", 5, "Good"));

    while (choice != 5) {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                inventory.addBook();
                break;
            case 2:
                inventory.editBook();
                break;
            case 3:
                inventory.deleteBook();
                break;
            case 4:
                std::cout << inventory;
                break;
            case 5:
                std::cout << "Exiting inventory system. Goodbye!" << std::endl;
                break;
        }
    }
    
    return 0;
}

void displayMenu() {
    std::cout << "\n--- Bookstore Inventory Menu ---\n";
    std::cout << "1. Add a new/used book\n";
    std::cout << "2. Edit a book's details\n";
    std::cout << "3. Delete a book\n";
    std::cout << "4. Show all books\n";
    std::cout << "5. Exit\n";
    std::cout << "--------------------------------\n";
}

int getMenuChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    while (std::cin.fail() || choice < 1 || choice > 5) {
        std::cout << "Invalid input. Please enter a number between 1 and 5: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> choice;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}