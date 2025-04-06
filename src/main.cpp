#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"
#include <iostream>



int main() {
    Library library;
    Librarian librarian(1, "John Doe");
    Member member(2, "Jane Smith");
    library.addUser(&librarian);
    library.addUser(&member);
    Book book1(1, "The Catcher in the Rye", "J.D. Salinger", 3);
    Book book2(2, "1984", "George Orwell", 2);
    library.addBook(book1);
    library.addBook(book2);  
    librarian.viewAllBooks(library.getBooks());
    member.borrowBook(library.getBooks(), 1);
    library.displayBooks();
    library.findUser(1);

    return 0;
}

