#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
protected: 
    std::string mTitle;
    std::string mAuthor;
    std::string mIsbn;
    int mQuantity;

public:
    Book();
    Book(const std::string& title, const std::string& author, const std::string& isbn, int quantity);
    virtual ~Book() {} 

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    int getQuantity() const;

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setIsbn(const std::string& isbn);
    void setQuantity(int quantity);

    
    virtual void displayDetails(std::ostream& os) const;

    friend bool operator==(const Book& lhs, const Book& rhs);
};


std::ostream& operator<<(std::ostream& os, const Book& book);

#endif 