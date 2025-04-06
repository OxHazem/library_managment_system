#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"
#include <iostream>

Member::Member(int id, string name) : User(id, name, "Member") {}

void Member::borrowBook(vector<Book>& books, int bookId) {
    for (auto& book : books) {  
        if (book.getBookId() == bookId && book.isAvailableForBorrowing()) {
            cout << "Book borrowed: " << book.getTitle() << endl;
            book.updateAvailability();  
            break;
        }
    }
}





void Member::returnBook(vector<Book>& books, int bookId) {
    for (auto& book : books) {
        if (book.getBookId() == bookId) {
            book.setAvailableCopies(book.getAvailableCopies() + 1);
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Member::viewAllBooks(const vector<Book>& books) const {
    for (const auto& book : books) {
        book.displayBookInfo();
    }
}
