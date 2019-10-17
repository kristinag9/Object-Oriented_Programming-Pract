#pragma once
#include "Song.h"
#include "Singer.h"

class Playlist
{
private:
    Song* songs;

    void copy(const Playlist& other);
    void erase();
    void resize();
protected:
    int capacity;
    int numberOfSongs;
public:
    Playlist();
    Playlist(const Playlist& other);
    Playlist& operator=(const Playlist& other);
    Playlist(Song* songs, int numberOfSongs);

    int getNumberOfSongs() const; //to be accessed other classes
    void sortSongs(); //getNameOfSinger() (bubbleSort)

    virtual void playNextSong(const Playlist& next);
    virtual void playByName(const Playlist& song);
    virtual bool isEmpty() const;

    virtual ~Playlist() {}
};

