#include "BookList.h"
#include "UsedBook.h" 
#include <iostream>
#include <limits>
#include <memory>


void BookList::addBook(std::unique_ptr<Book> book) {
    mBooks.push_back(std::move(book));
}

void BookList::addBook() {
    std::string type;
    std::cout << "\nIs this a 'new' or 'used' book? ";
    std::getline(std::cin, type);
    
    std::string title, author, isbn;
    int quantity;

    std::cout << "Enter Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);
    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    if (type == "used") {
        std::string condition;
        std::cout << "Enter Condition (e.g., Good, Fair): ";
        std::getline(std::cin, condition);
        mBooks.push_back(std::make_unique<UsedBook>(title, author, isbn, quantity, condition));
    } else {
        mBooks.push_back(std::make_unique<Book>(title, author, isbn, quantity));
    }
    
    std::cout << "\nBook added successfully!" << std::endl;
}

void BookList::editBook() {
    std::string isbn;
    std::cout << "\nEnter ISBN of the book to edit: ";
    std::getline(std::cin, isbn);

    Book* bookToEdit = findBookByIsbn(isbn);

    if (bookToEdit == nullptr) {
        std::cout << "Error: Book with that ISBN not found." << std::endl;
    } else {
        std::string newTitle, newAuthor;
        int newQuantity;

        std::cout << "Enter new Title (current: " << bookToEdit->getTitle() << "): ";
        std::getline(std::cin, newTitle);
        std::cout << "Enter new Author (current: " << bookToEdit->getAuthor() << "): ";
        std::getline(std::cin, newAuthor);
        std::cout << "Enter new Quantity (current: " << bookToEdit->getQuantity() << "): ";
        std::cin >> newQuantity;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bookToEdit->setTitle(newTitle);
        bookToEdit->setAuthor(newAuthor);
        bookToEdit->setQuantity(newQuantity);

        std::cout << "\nBook updated successfully!" << std::endl;
    }
}

void BookList::deleteBook() {
    std::string isbn;
    std::cout << "\nEnter ISBN of the book to delete: ";
    std::getline(std::cin, isbn);

    for (auto it = mBooks.begin(); it != mBooks.end(); ++it) {
        if ((*it)->getIsbn() == isbn) {
            mBooks.erase(it);
            std::cout << "\nBook deleted successfully!" << std::endl;
            return;
        }
    }
    std::cout << "Error: Book with that ISBN not found." << std::endl;
}

Book* BookList::findBookByIsbn(const std::string& isbn) {
    for (const auto& bookPtr : mBooks) {
        if (bookPtr->getIsbn() == isbn) {
            return bookPtr.get();
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const BookList& list) {
    os << "\n--- Current Inventory ---";
    if (list.mBooks.empty()) {
        os << "\nThe inventory is empty." << std::endl;
    } else {
        for (size_t i = 0; i < list.mBooks.size(); ++i) {
            os << "\n--- Book #" << (i + 1) << " ---\n";
            os << *(list.mBooks[i]); // Dereference pointer to print
        }
         os << std::endl;
    }
    os << "-----------------------\n";
    return os;
}