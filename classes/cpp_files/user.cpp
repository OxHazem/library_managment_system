#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"
#include <iostream>

User::User(int id, string n, string e, string r)
    : userId(id), name(n), email(e), role(r) {}

void User::getUserInfo() const {
    std::cout << "User ID: " << userId << "\n"
              << "Name: " << name << "\n"
              << "Email: " << email << "\n"
              << "Role: " << role << "\n";
}

int User::getUserId() const { return userId; }
string User::getName() const { return name; }
string User::getRole() const { return role; }