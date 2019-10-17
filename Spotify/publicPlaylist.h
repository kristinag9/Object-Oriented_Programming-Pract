#pragma once
#include "Playlist.h"

//publicPlaylist is a Playlist
class publicPlaylist : public Playlist
{
private:
    char* nameOfPublicPlaylist;

    void copy(const publicPlaylist& other);
    void erase();
    void resize();
public:
    publicPlaylist();
    publicPlaylist(const publicPlaylist& other);
    publicPlaylist& operator=(const publicPlaylist& other);
    ~publicPlaylist();

    publicPlaylist(const Song* songs, int numberOfSongs, int capacity, const char* nameOfPublicPlaylist);

    void playNextSong(const Playlist& next);
    void playByName(const Playlist& song);
    bool isEmpty() const;
};
