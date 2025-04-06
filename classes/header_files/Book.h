#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;
class Book {
private:
    int bookId;
    string title;
    string author;
    int availableCopies;
    bool isAvailable =true;

public:
    Book(int id, string t, string a, int copies);
    int getBookId() const;
    string getTitle() const;
    string getAuthor() const;
    int getAvailableCopies() const;
    bool isAvailableForBorrowing() const;
    void setAvailableCopies(int copies);
    void displayBookInfo() const;
    void updateAvailability();
    bool IsAvailble();
};

#endif 
