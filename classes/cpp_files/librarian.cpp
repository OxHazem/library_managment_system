#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include <iostream>
#include <limits>
#include <algorithm>

Librarian::Librarian(int id, string n, string e)
    : User(id, n, e, "Librarian") {}

void Librarian::addBook(vector<Book>& books) const {
    int id;
    string title, author;
    int copies;

    cout << "Enter Book ID: ";
    while (!(cin >> id) || id <= 0) {
        cout << "Invalid ID. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Check for duplicate ID
    if (any_of(books.begin(), books.end(), 
                  [id](const Book& b) { return b.getBookId() == id; })) {
        cout << "Book ID already exists!\n";
        return;
    }

    cin.ignore(); 
    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Available Copies: ";
    while (!(cin >> copies) || copies < 0) {
        cout << "Invalid input. Enter non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    books.emplace_back(id, title, author, copies);
    cout << "Book added successfully!\n";
}

void Librarian::removeBook(vector<Book>& books) const {
    if (books.empty()) {
        cout << "No books available to remove.\n";
        return;
    }

    int id;
    cout << "Enter Book ID to remove: ";
    while (!(cin >> id)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    auto it = find_if(books.begin(), books.end(), 
                         [id](const Book& b) { return b.getBookId() == id; });
    
    if (it != books.end()) {
        books.erase(it);
        cout << "Book removed successfully!\n";
    } else {
        cout << "Book not found!\n";
    }
}

void Librarian::viewAllBooks(const vector<Book>& books) const {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }
    for (const auto& book : books) {
        book.displayBookInfo();
        cout << "-----------------\n";
    }
}