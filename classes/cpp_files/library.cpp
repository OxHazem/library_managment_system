#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(int bookId) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getBookId() == bookId) {
            books.erase(it);
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
            std::cout<<"found the user"<<std::endl;
            return user;
        }
    }
    cout<<"didnot find the user"<<endl;
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
