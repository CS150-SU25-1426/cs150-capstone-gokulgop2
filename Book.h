#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string mTitle;     
    std::string mAuthor;
    std::string mIsbn;       
    int mQuantity;           

public:
    // onstructors
    Book();

   
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
