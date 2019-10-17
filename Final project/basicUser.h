#pragma once
#include "User.h"
#include "Ad.h"

//basicUser is a User
class basicUser : public User
{
public:
    basicUser(const char* name, const char* username, int age, bool gender, const char* birthdate, const char* password);
                                                         // : User(name, username, age, gender, birthdate, password)
    void playPlaylist(Playlist* playlist, const Ad& ad); //playNextSong x3 then playAd ... and repeat
};
