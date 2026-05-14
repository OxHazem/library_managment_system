#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "user.h"
#include "Book.h"
#include <vector>

class Librarian : public User {
public:
    Librarian(int id, string name);
    void addBook(vector<Book>& books, const Book& book);
    void removeBook(vector<Book>& books, int bookId);
    void updateBook(vector<Book>& books, int bookId, string newTitle, string newAuthor, int newCopies);
    void viewAllBooks(const vector<Book>& books) const;
};

#endif 
