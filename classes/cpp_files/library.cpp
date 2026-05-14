#include "../header_files/library.h"
#include <iostream>
#include <string>

// Callback to load books from DB
static int loadBooksCallback(void* data, int argc, char** argv, char** azColName) {
    auto* books = static_cast<vector<Book>*>(data);
    if (argc >= 4) {
        int id = std::stoi(argv[0]);
        string title = argv[1];
        string author = argv[2];
        int copies = std::stoi(argv[3]);
        Book b(id, title, author, copies);
        books->push_back(b);
    }
    return 0;
}

Library::Library() : db(nullptr) {
    initializeDatabase();
    loadBooksFromDB();
}

Library::~Library() {
    if (db) {
        syncToDB(); // Save any borrow state changes before closing
        sqlite3_close(db);
    }
}

void Library::initializeDatabase() {
    if (sqlite3_open("library.db", &db) != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
        return;
    }
    
    const char* sqlBooks = "CREATE TABLE IF NOT EXISTS Books ("
                           "ID INT PRIMARY KEY NOT NULL, "
                           "Title TEXT NOT NULL, "
                           "Author TEXT NOT NULL, "
                           "Copies INT NOT NULL, "
                           "IsAvailable INT NOT NULL);";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sqlBooks, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error creating Books table: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void Library::loadBooksFromDB() {
    if (!db) return;
    const char* sql = "SELECT ID, Title, Author, Copies, IsAvailable FROM Books;";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, loadBooksCallback, &books, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error loading books: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

void Library::syncToDB() {
    if (!db) return;
    for (auto& book : books) {
        string sql = "UPDATE Books SET Copies = " + std::to_string(book.getAvailableCopies()) + 
                     ", IsAvailable = " + (book.isAvailableForBorrowing() ? "1" : "0") + 
                     " WHERE ID = " + std::to_string(book.getBookId()) + ";";
        char* errMsg = nullptr;
        if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
            std::cerr << "SQL error updating book: " << errMsg << std::endl;
            sqlite3_free(errMsg);
        }
    }
}

void Library::addBook(const Book& book) {
    // Check if it already exists to avoid duplication
    bool exists = false;
    for (const auto& b : books) {
        if (b.getBookId() == book.getBookId()) {
            exists = true;
            break;
        }
    }
    
    if (!exists) {
        books.push_back(book);
        if (db) {
            string sql = "INSERT INTO Books (ID, Title, Author, Copies, IsAvailable) VALUES (" +
                         std::to_string(book.getBookId()) + ", '" + book.getTitle() + "', '" + 
                         book.getAuthor() + "', " + std::to_string(book.getAvailableCopies()) + ", " +
                         (book.isAvailableForBorrowing() ? "1" : "0") + ");";
            char* errMsg = nullptr;
            if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
                std::cerr << "SQL error inserting book: " << errMsg << std::endl;
                sqlite3_free(errMsg);
            }
        }
    }
}

void Library::removeBook(int bookId) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getBookId() == bookId) {
            books.erase(it);
            if (db) {
                string sql = "DELETE FROM Books WHERE ID = " + std::to_string(bookId) + ";";
                char* errMsg = nullptr;
                if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
                    std::cerr << "SQL error deleting book: " << errMsg << std::endl;
                    sqlite3_free(errMsg);
                }
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

void Library::addUser(User* user) {
    users.push_back(user);
}

void Library::displayBooks() const {
    for (const auto& book : books) {
        book.displayBookInfo();
    }
}

User* Library::findUser(int userId) const {
    for (auto user : users) {
        if (user->getUserId() == userId) {
            std::cout << "found the user" << std::endl;
            return user;
        }
    }
    cout << "didnot find the user" << endl;
    return nullptr;
}

void Library::searchBookByTitle(const string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            book.displayBookInfo();
        }
    }
}

vector<Book>& Library::getBooks(){
    return books;
}
