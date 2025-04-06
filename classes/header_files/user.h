#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
class User {
protected:
    int userId;
    string name;
    string role;

public:
    User(int id, std::string n, std::string r);
    int getUserId() const;
    string getName() const;
    string getRole() const;
};

#endif 
