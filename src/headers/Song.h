
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
    ~Song() override;

    static int getTotalSongs();
    Playlist* getParentAlbum();
    void play() override;
    void pause() override;
};


#endif //SOUNDAPP_SONG_H