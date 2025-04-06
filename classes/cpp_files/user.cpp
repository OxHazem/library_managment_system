#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"

User::User(int id, string n, string r) : userId(id), name(n), role(r) {}

int User::getUserId() const {
    return userId;
}

string User::getName() const {
    return name;
}

string User::getRole() const {
    return role;
}
