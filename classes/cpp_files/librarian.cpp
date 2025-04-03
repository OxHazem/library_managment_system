#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
void librarian :: addBook(library * mainlibrary){
    int bookId;
    int avialblecopies;
    string title ;
    string AuthorName;
    cout << "Enter the book Id: "<<endl;
    cin >> bookId ;
    cout << "Enter the Number of copies: "<<endl;
    cin >> avialblecopies;
    cout<<"Enter the Title : "<<endl ; 
    cin>>title ; 
    cout<<"Enter the Authour Name : "<<endl ; 
    cin>> AuthorName ; 
    Book newbook = Book(bookId, title, AuthorName, avialblecopies, true);
    mainlibrary ->Addbook(newbook);
}
void librarian ::removeBook(int id , library * mainlibrary ){
}