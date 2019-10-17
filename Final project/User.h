#pragma once
#include "Playlist.h"
#include "privateLibrary.h"
#include "Library.h"

class User
{
private:
    char* name;
    char* username;
    int age;
    bool gender; //1 -> female, 0 -> male
    char birthDate[11]; //01/01/2000 + '\0'
    char* password;
    publicLibrary library;
    privateLibrary plibrary;

    void copy(const User& other);
    void erase();
public:
    User();
    User(const User& other);
    User& operator=(const User& other);
    User(const char* name, const char* username, int age, bool gender, const char* birthdate, const char* password,
          publicLibrary library, privateLibrary plibrary);

    const char* getName() const;
    const char* getUsername() const;
    /*int getAge() const;
    bool getGender() const;
    const char* getBirthDate() const;
    const char* getPassword() const;*/

    void playPlaylist(const Playlist& playlist);
    virtual ~User() {}
};
