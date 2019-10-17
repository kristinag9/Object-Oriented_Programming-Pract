#pragma once

enum Genre
{
    POP, ROCK, CLASSICAL, RNB, JAZZ, DANCE, HOUSE
};

class Song
{
private:
    char* nameOfSong;
    char* dateOfProduction;
    int numberOfWatching; //every time when an object of the class is created -> the numberOfWatching++
    Genre genre; //the type of genre is enum with random constants

    void copy(const Song& other);
    void erase();
public:
    Song();
    Song(const Song& other);
    Song& operator=(const Song& other);
    Song(const char* nameOfSong, const char* dateOfProduction, int numberOfWatching, Genre genre);

    const char getNameOfSong() const;
    void playSong(const Song& song); //numberOfWatching++

    virtual ~Song() {}
};


