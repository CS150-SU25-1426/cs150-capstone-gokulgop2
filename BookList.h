#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "Book.h"
#include <vector>
#include <string>

class BookList {
private:
    std::vector<Book> mBooks;

public:
    void addBook();
    void editBook();
    void deleteBook();
    

    Book* findBookByIsbn(const std::string& isbn);

    // operator ovrload
    BookList& operator+=(const Book& book);
    friend std::ostream& operator<<(std::ostream& os, const BookList& list);
};

#endif