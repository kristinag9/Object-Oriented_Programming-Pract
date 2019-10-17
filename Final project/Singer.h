#pragma once
#include "Song.h"
#include "Playlist.h"
#include "User.h"
#include "publicPlaylist.h"
#include "privateLibrary.h"

class Singer : public User
{
private:
    char* nationality;
    int subscribers;
    void copy(const Singer& other);
    void erase();
public:
    Singer();
    Singer(const Singer& other);
    Singer& operator=(const Singer& other);
    Singer(const char* name, const char* username, int age, bool gender, const char* birthdate, const char* password,
           publicLibrary library, privateLibrary plibrary, const char* nationality, int subscribers);

    void setSingerName(const char* singerName);
    const char* getNameOfSinger() const; //to be accessible for its inheritors

    void uploadSong(Playlist* playlist, const Song& song); //return this->getNumberOfSongs()++
    void deleteSong(Playlist* playlist, int index); //return this->getNumberOfSongs()--

    ~Singer();
};
