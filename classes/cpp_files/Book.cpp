#include "D:\DownLoad\projects\OOPproject\classes\header_files\Book.h"
Book :: Book(int book_ID,string title,string authourname,int availblecopies,bool Isavailble){
    BookID=book_ID;
    Title=title;
    AuthourName=authourname;
    IsAvailble=Isavailble;
}
void Book :: DisplayBookInfo(){
    cout<<"BookId : "<<BookID <<endl;
    cout<<"Book Title : "<<Title <<endl;
    cout<<"Book AuthourName : "<<AuthourName << endl ;
    cout<<"Book Availble copies : " <<AvailbleCopies <<endl;
    if (IsAvailble){
        cout<<"Book Availbele : "<< "NO" <<endl; 
    }else{
        cout<<"Book Availbele : "<< "YES" <<endl; 

    }
}
bool Book :: updateavailbaility(){

    if (AvailbleCopies>0){
        return true;
    }else{
        return false;
    }
}
int Book :: getbookid(){
    return BookID;

}
int Book ::deCAvailblecount(){
    return AvailbleCopies--;
}
int Book ::incAvailblecount(){
    return AvailbleCopies ++ ;
}
int Book ::getAvailblecopies(){
    return AvailbleCopies;
}

