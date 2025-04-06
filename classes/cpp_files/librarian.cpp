#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include <iostream>

Librarian::Librarian(int id, string name) : User(id, name, "Librarian") {}

void Librarian::addBook(vector<Book>& books, const Book& book) {
    books.push_back(book);
    std::cout << "Book \"" << book.getTitle() << "\" added successfully.\n";
}

void Librarian::removeBook(vector<Book>& books, int bookId) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getBookId() == bookId) {
            books.erase(it);
            cout << "Book removed successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Librarian::updateBook(vector<Book>& books, int bookId, string newTitle, string newAuthor, int newCopies) {
    for (auto& book : books) {
        if (book.getBookId() == bookId) {
            book.setAvailableCopies(newCopies);
            cout << "Book updated successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Librarian::viewAllBooks(const vector<Book>& books) const {
    for (const auto& book : books) {
        book.displayBookInfo();
    }
}
