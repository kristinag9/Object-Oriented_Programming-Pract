#pragma once
#include "privatePlaylist.h"
#include <vector>

using namespace std;

//Library contains only private playlists of songs
class privateLibrary
{
private:
    vector <Playlist* > playlists;
public:
    privateLibrary();
    vector <privatePlaylist* > getPrivateLibrary() const; //return privatePlaylist
};

