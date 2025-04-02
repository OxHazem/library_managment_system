#ifndef Book_H
#define Book_H
#include <iostream>
#include <string>
using namespace std ; 
class Book {
    private: 
        int BookID ;
        string Title;
        string AuthourName;
        int AvailbleCopies;
        bool IsAvailble ;
    public : 
        Book(int book_ID,string title,string authourname,int availblecopies,bool Isavailble=true){}
        void DisplayBookInfo(){}
        bool updateavailbaility(){}
        int getbookid(){}
        int deCAvailblecount(){}
        int incAvailblecount(){}
        int getAvailblecopies(){}

};








#endif