#include "BookList.h"
#include <iostream>
#include <limits>


void BookList::addBook() {
    std::string title, author, isbn;
    int quantity;

    std::cout << "\nEnter Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);
    std::cout << "Enter Quantity: ";
    std::cin >> quantity;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    mBooks.push_back(Book(title, author, isbn, quantity));
    std::cout << "Book added successfully!" << std::endl;
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

        std::cout << "Enter new Title: ";
        std::getline(std::cin, newTitle);
        std::cout << "Enter new Author: ";
        std::getline(std::cin, newAuthor);
        std::cout << "Enter new Quantity: ";
        std::cin >> newQuantity;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bookToEdit->setTitle(newTitle);
        bookToEdit->setAuthor(newAuthor);
        bookToEdit->setQuantity(newQuantity);

        std::cout << "Book updated successfully!" << std::endl;
    }
}


void BookList::deleteBook() {
    std::string isbn;
    std::cout << "\nEnter ISBN of the book to delete: ";
    std::getline(std::cin, isbn);

    for (auto it = mBooks.begin(); it != mBooks.end(); ++it) {
        if (it->getIsbn() == isbn) {
            mBooks.erase(it);
            std::cout << "Book deleted successfully!" << std::endl;
            return;
        }
    }
    std::cout << "Error: Book with that ISBN not found." << std::endl;
}


Book* BookList::findBookByIsbn(const std::string& isbn) {
    for (auto& book : mBooks) {
        if (book.getIsbn() == isbn) {
            return &book; 
        }
    }
    return nullptr; 
}

//Operators


BookList& BookList::operator+=(const Book& book) {
    mBooks.push_back(book);
    return *this;
}

// Overloads operator
std::ostream& operator<<(std::ostream& os, const BookList& list) {
    os << "\n--- Current Inventory ---\n";
    if (list.mBooks.empty()) {
        os << "The inventory is empty." << std::endl;
    } else {
        for (size_t i = 0; i < list.mBooks.size(); ++i) {
            os << "--- Book #" << (i + 1) << " ---\n";
            os << list.mBooks[i] << std::endl;
        }
    }
    os << "-----------------------\n";
    return os;
}