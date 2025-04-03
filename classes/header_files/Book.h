#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;
class Book {
private:
    int bookId;
    string title;
    string author;
    int availableCopies;

public:
    Book(int id, string t, string a, int copies);
    
    void displayBookInfo() const;
    int getBookId() const;
    string getTitle() const;
    int getAvailableCopies() const;
    void decreaseCopies();
    void increaseCopies();
};

#endif









