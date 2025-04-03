#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include <vector>

class Librarian : public User {
public:
    Librarian(int id, std::string name);
    void addBook(std::vector<Book>& books, const Book& book);
    void removeBook(std::vector<Book>& books, int bookId);
    void updateBook(std::vector<Book>& books, int bookId, std::string newTitle, std::string newAuthor, int newCopies);
    void viewAllBooks(const std::vector<Book>& books) const;
};

#endif // LIBRARIAN_H
