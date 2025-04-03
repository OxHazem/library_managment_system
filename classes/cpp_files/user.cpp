#include "D:\DownLoad\projects\OOPproject\classes\header_files\user.h"

User::User(int id, std::string n, std::string r) : userId(id), name(n), role(r) {}

int User::getUserId() const {
    return userId;
}

std::string User::getName() const {
    return name;
}

std::string User::getRole() const {
    return role;
}
