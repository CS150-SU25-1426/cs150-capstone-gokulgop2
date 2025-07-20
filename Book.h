#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string mTitle;      // The book's title (the "name" requirement)
    std::string mAuthor;
    std::string mIsbn;       // A unique identifier for the book
    int mQuantity;           // The "at least one attribute" requirement

public:
    // Default Constructor
    Book();

    // Parameterized Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn, int quantity);

    
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    int getQuantity() const;

   
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setIsbn(const std::string& isbn);
    void setQuantity(int quantity);

    
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend bool operator==(const Book& lhs, const Book& rhs);
};

#endif 