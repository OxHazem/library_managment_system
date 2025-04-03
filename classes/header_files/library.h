#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<std::unique_ptr<User>> users;

public:
    Book* findBook(int bookId);
    User* getUser(int userId);
    void addUser(std::unique_ptr<User> user);
    void borrowBook(int bookId, int userId);
    void returnBook(int bookId, int userId);
    void searchBook() const;
    const std::vector<Book>& getBooks() const;
};

#endif