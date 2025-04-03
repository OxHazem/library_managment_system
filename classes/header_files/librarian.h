#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include <vector>
using namespace std;
class Book; 

class Librarian : public User {
public:
    Librarian(int id, string n, string e);
    
    void addBook(vector<Book>& books) const;
    void removeBook(std::vector<Book>& books) const;
    void viewAllBooks(const std::vector<Book>& books) const;
};

#endif