#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include <string>
#include <sqlite3.h>
#include "user.h"
#include "Book.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<User*> users;
    sqlite3* db;

    void initializeDatabase();
    void loadBooksFromDB();
    void loadUsersFromDB();

public:
    Library();
    ~Library();

    void addBook(const Book& book);
    void removeBook(int bookId);
    void addUser(User* user);
    void displayBooks() const;
    User* findUser(int userId) const;
    void searchBookByTitle(const string& title) const;

    void syncToDB(); // Save updates (like copies borrowed) to DB

    vector<Book>& getBooks();
};

#endif // LIBRARY_H
