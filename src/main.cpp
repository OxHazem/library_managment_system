#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"
#include <iostream>



int main() {
    // Create the library and users
    Library library;
    Librarian librarian(1, "John Doe");
    Member member(2, "Jane Smith");

    library.addUser(&librarian);
    library.addUser(&member);

    // Create and add books
    Book book1(1, "The Catcher in the Rye", "J.D. Salinger", 3);
    Book book2(2, "1984", "George Orwell", 2);

    library.addBook(book1);
    library.addBook(book2);

    // Librarian views all books
    librarian.viewAllBooks(library.getBooks());

    // Member borrows a book
    member.borrowBook(library.getBooks(), 1);

    // Display all books after borrowing
    library.displayBooks();

    return 0;
}

