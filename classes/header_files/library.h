#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"


class Library {
private:
    vector<Book> books;
    vector<User*> users;

public:
    void addBook(const Book& book);
    void removeBook(int bookId);
    void addUser(User* user);
    void displayBooks() const;
    User* findUser(int userId) const;
    void searchBookByTitle(const string& title) const;

    // Getter for books vector
    // const std::vector<Book>& getBooks() const;
    vector<Book>  & getBooks();
};

#endif // LIBRARY_H
