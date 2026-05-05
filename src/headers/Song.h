
#ifndef SOUNDAPP_SONG_H
#define SOUNDAPP_SONG_H
#include "AudioItem.h"

class Playlist;

/**
 * Concrete AudioItem representing a music track. Carries its own copy of the
 * audio metadata (id, name, duration, thumbnail, owners) and implements the
 * full AudioItem interface. Optionally back-references the album (Playlist)
 * it belongs to.
 */
class Song: public AudioItem {
private:
    static int totalSongs;
    int audioItemId;
    std::string audioItemName;
    int audioItemDuration;
    std::string audioItemThumbNailPath;
    Artist** owners;
    int ownersCount;

    Playlist* parentAlbum;     // back-reference

public:
    Song(std::string songName, int songDuration, std::string songThumbNail, Artist** songOwners, int songOwnerCount, Playlist* parentAlbum);
    ~Song() override;

    static int getTotalSongs();
    Playlist* getParentAlbum();

    std::string getAudioItemName() override;
    int getAudioItemDuration() override;
    int getAudioItemId() override;
    std::string getAudioItemThumbNailPath() override;
    Artist** getOwners() override;
    int getOwnersCount() override;
    bool setAudioItemName(std::string newAudioName) override;

    void play() override;
    void pause() override;
};


#endif //SOUNDAPP_SONG_H
