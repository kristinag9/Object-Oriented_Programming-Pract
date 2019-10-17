#pragma once
#include "User.h"

class premiumUser : public User
{
private:
    char* offlineSongs;
    int sizeOfOfflineSongs;

    void copy(const premiumUser& other);
    void erase();
    void resize();
public:
    premiumUser();
    premiumUser(const premiumUser& other);
    premiumUser& operator=(const premiumUser& other);
    ~premiumUser();

    premiumUser(const char* name, const char* username, int age, bool gender, const char* birthdate, const char* password,
                const char* offlineSongs, int sizeOfOfflineSongs); // : User(name, username, age, gender, birthdate, password)
    void playPlaylist(Playlist* playlist);
};
