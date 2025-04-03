#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"

Book::Book(int id, string t, string a, int copies)
    : bookId(id), title(t), author(a), availableCopies(copies) {}

void Book::displayBookInfo() const {
    cout << "Book ID: " << bookId << "\n"
              << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Available Copies: " << availableCopies << "\n";
}

int Book::getBookId() const { return bookId; }
string Book::getTitle() const { return title; }
int Book::getAvailableCopies() const { return availableCopies; }
void Book::decreaseCopies() { if (availableCopies > 0) availableCopies--; }
void Book::increaseCopies() { availableCopies++; }