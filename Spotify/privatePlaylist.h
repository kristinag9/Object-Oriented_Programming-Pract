#pragma once
#include "Playlist.h"

//privatePlaylist is a Playlist
class privatePlaylist : public Playlist
{
private:
    char* nameOfPrivatePlaylist;

    void copy(const privatePlaylist& other);
    void erase();
    void resize();
public:
    privatePlaylist();
    privatePlaylist(const privatePlaylist& other);
    privatePlaylist& operator=(const privatePlaylist& other);
    ~privatePlaylist();

    privatePlaylist(const Song* songs, int numberOfSongs, int capacity, const char* nameOfPrivatePlaylist);

    void playNextSong(const Playlist& next);
    void playByName(const Playlist& song);
    bool isEmpty() const;
};
