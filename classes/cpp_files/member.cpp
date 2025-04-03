#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include <iostream>
#include <algorithm>

Member::Member(int id, string n, string e)
    : User(id, n, e, "Member") {}

const vector<int>& Member::getBorrowedBooks() const { 
    return borrowedBooks; 
}

bool Member::hasBorrowed(int bookId) const {
    return find(borrowedBooks.begin(), borrowedBooks.end(), bookId) != borrowedBooks.end();
}

void Member::borrowBook(int bookId) {
    borrowedBooks.push_back(bookId);
}

void Member::returnBook(int bookId) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    }
}

void Member::viewBorrowedBooks(const vector<Book>& allBooks) const {
    if (borrowedBooks.empty()) {
        cout << "No books borrowed.\n";
        return;
    }
    
    bool foundAny = false;
    for (int bookId : borrowedBooks) {
        for (const auto& book : allBooks) {
            if (book.getBookId() == bookId) {
                book.displayBookInfo();
                cout << "-----------------\n";
                foundAny = true;
                break;
            }
        }
    }
    
    if (!foundAny) {
        cout << "Borrowed books not found in library records.\n";
    }
}