#include <iostream>
#include "Book.h" 

int main() {
    std::cout << "--- Testing Book Class ---\n" << std::endl;

    // 1.
    Book book1("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803", 42);
    Book book2;

    // 2.
    book2.setTitle("Dune");
    book2.setAuthor("Frank Herbert");
    book2.setIsbn("978-0441013593");
    book2.setQuantity(25);

    // 3.
    std::cout << "--- Displaying Book 1 ---" << std::endl;
    std::cout << book1 << std::endl;

    std::cout << "\n--- Displaying Book 2 ---" << std::endl;
    std::cout << book2 << std::endl;

    // 4.
    std::cout << "\n--- Comparing Books ---" << std::endl;
    std::cout << "Are Book 1 and Book 2 the same? (0=false, 1=true): " << (book1 == book2) << std::endl;

    
    Book book3("The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "978-0345391803", 10);
    std::cout << "Are Book 1 and Book 3 the same? (0=false, 1=true): " << (book1 == book3) << std::endl;
    
    return 0;
}