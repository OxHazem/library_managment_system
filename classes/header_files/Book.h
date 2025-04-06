#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int bookId;
    std::string title;
    std::string author;
    int availableCopies;
    bool isAvailable =true;

public:
    Book(int id, std::string t, std::string a, int copies);
    int getBookId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getAvailableCopies() const;
    bool isAvailableForBorrowing() const;
    void setAvailableCopies(int copies);
    void displayBookInfo() const;
    void updateAvailability();
    bool IsAvailble();
};

#endif // BOOK_H
