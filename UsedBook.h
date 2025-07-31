#ifndef USEDBOOK_H
#define USEDBOOK_H

#include "Book.h"

class UsedBook : public Book {
private:
    std::string mCondition;

public:
    UsedBook(const std::string& title, const std::string& author, const std::string& isbn, int quantity, const std::string& condition);

    //overide
    void displayDetails(std::ostream& os) const override;
};

#endif 