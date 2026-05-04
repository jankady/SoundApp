
#ifndef SOUNDAPP_SONG_H
#define SOUNDAPP_SONG_H
#include "AudioItem.h"

class Playlist;

/**
 * Concrete AudioItem representing a music track. Optionally back-references
 * the album (Playlist) it belongs to. Implements play()/pause() with simple
 * console output to demonstrate late binding via AudioItem*.
 */
class Song: public AudioItem {
private:
    static int totalSongs;     // running count of live songs
    Playlist* parentAlbum;     // back-reference, NOT owned

public:
    Song(std::string songName, int songDuration, std::string songThumbNail, Artist** songOwners, int songOwnerCount ,Playlist* parentAlbum);
    ~Song() override;

    static int getTotalSongs();
    Playlist* getParentAlbum();

    void play() override;      // overrides pure virtual AudioItem::play
    void pause() override;
};


#endif //SOUNDAPP_SONG_H
