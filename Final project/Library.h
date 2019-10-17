#pragma once
#include "publicPlaylist.h"
#include <vector>

using namespace std;

//Library contains only public playlists of songs
class publicLibrary
{
private:
    vector <Playlist* > playlists;
public:
    publicLibrary();
    vector <publicPlaylist* > getPublicLibrary() const; //return publicPlaylist
};
