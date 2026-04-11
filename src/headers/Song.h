
#ifndef SOUNDAPP_SONG_H
#define SOUNDAPP_SONG_H
#include "AudioItem.h"

class Playlist;

class Song: public AudioItem {
private:
    static int totalSongs; // Static member to keep track of total songs created
    Playlist* parentAlbum;

public:
    Song(std::string songName, int songDuration, std::string songThumbNail, Artist** songOwners, int songOwnerCount ,Playlist* parentAlbum);
    ~Song();

    static int getTotalSongs();
    Playlist* getParentAlbum();
    virtual void play();
    virtual void pause();
};


#endif //SOUNDAPP_SONG_H