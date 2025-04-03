#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"
#include <iostream>

Member::Member(int id, std::string name) : User(id, name, "Member") {}

void Member::borrowBook(std::vector<Book>& books, int bookId) {
    for (auto& book : books) {  // Use a non-const reference to modify the book
        if (book.getBookId() == bookId && book.isAvailable()) {
            std::cout << "Book borrowed: " << book.getTitle() << std::endl;
            book.updateAvailability(false);  // Modify the availability of the book
            break;
        }
    }
}





void Member::returnBook(std::vector<Book>& books, int bookId) {
    for (auto& book : books) {
        if (book.getBookId() == bookId) {
            book.setAvailableCopies(book.getAvailableCopies() + 1);
            std::cout << "Book returned successfully.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Member::viewAllBooks(const std::vector<Book>& books) const {
    for (const auto& book : books) {
        book.displayBookInfo();
    }
}
