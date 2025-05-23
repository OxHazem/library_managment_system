#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include <iostream>

Book::Book(int id, string t, string a, int copies)
    : bookId(id), title(t), author(a), availableCopies(copies), isAvailable(copies > 0) {}

int Book::getBookId() const {
    return bookId;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

int Book::getAvailableCopies() const {
    return availableCopies;
}

bool Book::isAvailableForBorrowing() const {
    return isAvailable;
}

void Book::setAvailableCopies(int copies) {
    availableCopies = copies;
    isAvailable = copies > 0;
}

void Book::displayBookInfo() const {
    cout << "ID: " << bookId << ", Title: " << title << ", Author: " << author 
              << ", Available Copies: " << availableCopies << "\n";
}

void Book::updateAvailability() {
    isAvailable = availableCopies > 0;
}
bool Book::IsAvailble(){
    return isAvailable;
}