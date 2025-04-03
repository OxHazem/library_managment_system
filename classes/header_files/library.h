#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"

class library {
private : 
    vector<Book>books;
    vector<user>users;
    vector<Book>borrowedbook;
    vector<librarian>librarians;
    vector<memeber>members;
public : 
    library (){}
    void AddUser(user){}
    void Addbook (Book){}
    bool borrowBook(int bookid,int userID){}
    bool returnBook (int bookId,int userId){}
    void SearchBook(string title){}
    void viewallbooks(){}
    void viewBorrowedBooks(){}
    vector<Book> getallbooks(){}


};









#endif // LIBRARY_H