#pragma once
#include "Song.h"

//Ad is a kind of Song
class Ad : public Song
{
private:
    double duration; //in seconds
public:
    Ad();
    Ad(const char* nameOfSong, const char* dateOfProduction, int numberOfWatching, Genre genre, double duration);
    void playAd(const Ad& ad);
    bool isAvailable() const; //duration => 30 && duration <= 60
};
