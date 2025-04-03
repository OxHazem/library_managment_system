#ifndef MEMBER_H
#define MEMBER_H

#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include <vector>

class Member : public User {
public:
    Member(int id, std::string name);
    void borrowBook(std::vector<Book>& books, int bookId);



    void returnBook(std::vector<Book>& books, int bookId);
    void viewAllBooks(const std::vector<Book>& books) const;
};

#endif // MEMBER_H
