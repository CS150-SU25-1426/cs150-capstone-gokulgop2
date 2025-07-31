#include "UsedBook.h"

//constructor calls
UsedBook::UsedBook(const std::string& title, const std::string& author, const std::string& isbn, int quantity, const std::string& condition)
    : Book(title, author, isbn, quantity) {
    mCondition = condition;
}

// overriden display
void UsedBook::displayDetails(std::ostream& os) const {
    Book::displayDetails(os); // First, call the base class version to print common info
    os << "\nCondition: " << mCondition; // Then, add the unique info for this class
}