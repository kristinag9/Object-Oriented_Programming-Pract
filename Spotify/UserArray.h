#pragma once
#include "User.h"

class UserArray
{
private:
    User** users;
    int numberOfUsers;
    int capacity;

    void erase();
    void copy(const UserArray& other);
    void resize();
public:
    UserArray();
    UserArray(const UserArray& other);
    UserArray& operator=(const UserArray& other);
    ~UserArray();
    UserArray(const User** user, int numberOfUsers, int capacity);

    void addUser(const User& user);
    void removeUser(int index);

    bool isLogin() const;
    bool isBasic() const;
    bool isPremium() const;
};


