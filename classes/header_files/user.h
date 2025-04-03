#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
class User {
protected:
    int userId;
    string name;
    string email;
    string role; // "Librarian" or "Member"

public:
    User(int id, string n, string e, string r);
    virtual ~User() = default;
    
    virtual void getUserInfo() const;
    int getUserId() const;
    string getName() const;
    string getRole() const;
};

#endif