#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    int userId;
    std::string name;
    std::string role;

public:
    User(int id, std::string n, std::string r);
    int getUserId() const;
    std::string getName() const;
    std::string getRole() const;
};

#endif // USER_H
