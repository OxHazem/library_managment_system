#ifndef MEMBER_H
#define MEMBER_H

#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include <vector>

class Member : public User {
public:
    Member(int id, string name);
    void borrowBook(vector<Book>& books, int bookId);



    void returnBook(vector<Book>& books, int bookId);
    void viewAllBooks(const vector<Book>& books) const;
};

#endif 
