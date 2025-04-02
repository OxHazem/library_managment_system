#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
void library ::Addbook(Book newbook){
    books.push_back(newbook);
}
void library ::AddUser(user newuser){
    users.push_back(newuser);
}
bool library ::borrowBook(int bookid,int userID){
    for(int memeber=0 ;memeber<members.size();memeber++){
        if(members[memeber].getuserId()==userID){
            cout<<"He is member "<<endl ;
            cout<<"borrowing the book !!!!!"<<endl;
        }else{
            cout <<"He is not memeber ";
                  return false ;  
        }
    }
    for (int book=0 ;book<books.size();book++){
           if(books[book].getbookid()==bookid){
                if (books[book].getAvailblecopies()>0){
                books[book].deCAvailblecount();
                }else{
                    cout<<"the book is not availble at the moment"<<endl;
                    return false;
                }
            }  
    }



}
void library ::viewallbooks(){
    for(int i =0 ; i<books.size();i++){
        books[i].DisplayBookInfo()
        
    }
}
