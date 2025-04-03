#ifndef LIBRARIAN_H
#define LIBRARIAN_h
#include<iostream>
#include<string>
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
using namespace std;
class librarian : public user{
public :
    librarian(int user_id,string email , string name,string role ): user(user_id,email,name,"librarian"){}
    void addBook(library * mainlibrary){}
    void removeBook(int book_ID , library * mainlibrary ){}
    void updateBook(int book_ID){}
    void viewallBook(){}
    void viewborrowedBooks(){}
    

};










#endif