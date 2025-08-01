#include "Book.h"
#include <iostream>

Book::Book() {
    mQuantity = 0;
}

Book::Book(const std::string& title, const std::string& author, const std::string& isbn, int quantity) {
    mTitle = title;
    mAuthor = author;
    mIsbn = isbn;
    mQuantity = quantity;
}

std::string Book::getTitle() const { return mTitle; }
std::string Book::getAuthor() const { return mAuthor; }
std::string Book::getIsbn() const { return mIsbn; }
int Book::getQuantity() const { return mQuantity; }

void Book::setTitle(const std::string& title) { mTitle = title; }
void Book::setAuthor(const std::string& author) { mAuthor = author; }
void Book::setIsbn(const std::string& isbn) { mIsbn = isbn; }
void Book::setQuantity(int quantity) {
    if (quantity >= 0) {
        mQuantity = quantity;
    }
}


void Book::displayDetails(std::ostream& os) const {
    os << "Title:     " << mTitle << std::endl;
    os << "Author:    " << mAuthor << std::endl;
    os << "ISBN:      " << mIsbn << std::endl;
    os << "Quantity:  " << mQuantity << std::endl;
    os << "Type:      New";
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    book.displayDetails(os);
    return os;
}

bool operator==(const Book& lhs, const Book& rhs) {
    return lhs.getIsbn() == rhs.getIsbn();
}