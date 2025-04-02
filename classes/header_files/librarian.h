#ifndef LIBRARIAN_H
#define LIBRARIAN_h
#include<iostream>
#include<string>
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
using namespace std;
class librarian : public user{
public : 
    void addBook(Book newBook){}
    void removeBook(int book_ID ){}
    void updateBook(int book_ID){}
    void viewallBook(){}
    void viewborrowedBooks(){}

};










#endif