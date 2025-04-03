#ifndef MEMEBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
using namespace std ;

class memeber : public user {
private:
    vector<int>memeber_borrowed_books;  
public : 
    memeber(int user_id,string email , string name,string role) : user(user_id,email,name,"memeber"){}
    void borrowBook(int book_ID){}
    void returnBook (int bookid){}
    void viewborrowedBook(){}
    void searchBook(string title){}

};











#endif