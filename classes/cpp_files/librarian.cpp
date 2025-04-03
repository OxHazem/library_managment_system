#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include <iostream>

Librarian::Librarian(int id, std::string name) : User(id, name, "Librarian") {}

void Librarian::addBook(std::vector<Book>& books, const Book& book) {
    books.push_back(book);
    std::cout << "Book \"" << book.getTitle() << "\" added successfully.\n";
}

void Librarian::removeBook(std::vector<Book>& books, int bookId) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getBookId() == bookId) {
            books.erase(it);
            std::cout << "Book removed successfully.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Librarian::updateBook(std::vector<Book>& books, int bookId, std::string newTitle, std::string newAuthor, int newCopies) {
    for (auto& book : books) {
        if (book.getBookId() == bookId) {
            book.setAvailableCopies(newCopies);
            std::cout << "Book updated successfully.\n";
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Librarian::viewAllBooks(const std::vector<Book>& books) const {
    for (const auto& book : books) {
        book.displayBookInfo();
    }
}
