#ifndef MEMBER_H
#define MEMBER_H

#include "user.h"
#include "Book.h"
#include <vector>

class Member : public User {
public:
    Member(int id, string name);
    void borrowBook(vector<Book>& books, int bookId);



    void returnBook(vector<Book>& books, int bookId);
    void viewAllBooks(const vector<Book>& books) const;
};

#endif 
