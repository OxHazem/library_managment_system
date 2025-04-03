#include <iostream>
#include<string>
using namespace std;
#include "D:\\DownLoad\\projects\\OOPproject\\classes\\header_files\\user.h"






user::user(int user_id , string email , string name,string role):User_ID(user_id),Email(email),Name(name),Role(role){}
void user:: Display(){
    cout<<"User_ID : "<<User_ID << endl ;
        cout<<"Email   : "<<Email << endl ;
        cout<<"Name    : "<<Name  << endl ;  
        cout<<"Role     : "<<Role << endl ; 
}
int user ::getuserId(){
    return User_ID ;
}
string user::getName(){
    return Name;
}
string user ::getrole(){

    return Role;
}