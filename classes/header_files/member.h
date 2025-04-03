#ifndef MEMBER_H
#define MEMBER_H

#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include <vector>
using namespace std;
class Book; // Forward declaration

class Member : public User {
private:
    vector<int> borrowedBooks;

public:
    Member(int id, string n, string e);
    
    const vector<int>& getBorrowedBooks() const;
    bool hasBorrowed(int bookId) const;
    void borrowBook(int bookId);
    void returnBook(int bookId);
    void viewBorrowedBooks(const vector<Book>& allBooks) const;
};

#endif