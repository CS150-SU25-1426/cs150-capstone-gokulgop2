#include "Book.h"
#include <iostream>
#include <iomanip>


Book::Book() {
    mQuantity = 0;
}


Book::Book(const std::string& title, const std::string& author, const std::string& isbn, int quantity) {
    mTitle = title;
    mAuthor = author;
    mIsbn = isbn;
    mQuantity = quantity;
}


std::string Book::getTitle() const {
    return mTitle;
}
std::string Book::getAuthor() const {
    return mAuthor;
}
std::string Book::getIsbn() const {
    return mIsbn;
}
int Book::getQuantity() const {
    return mQuantity;
}


void Book::setTitle(const std::string& title) {
    mTitle = title;
}
void Book::setAuthor(const std::string& author) {
    mAuthor = author;
}
void Book::setIsbn(const std::string& isbn) {
    mIsbn = isbn;
}
void Book::setQuantity(int quantity) {
    if (quantity >= 0) { 
        mQuantity = quantity;
    }
}



//Overloads
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Title:     " << book.mTitle << std::endl;
    os << "Author:    " << book.mAuthor << std::endl;
    os << "ISBN:      " << book.mIsbn << std::endl;
    os << "Quantity:  " << book.mQuantity;
    return os;
}


bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.mIsbn == rhs.mIsbn;
}