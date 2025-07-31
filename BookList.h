#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "Book.h"
#include <vector>
#include <string>
#include <memory> 

class BookList {
private:
    std::vector<std::unique_ptr<Book>> mBooks;

public:
    void addBook(); // This is your existing function for user input
    void addBook(std::unique_ptr<Book> book);
    void editBook();
    void deleteBook();
    
    Book* findBookByIsbn(const std::string& isbn);

    friend std::ostream& operator<<(std::ostream& os, const BookList& list);
};

#endif 