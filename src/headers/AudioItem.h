
#ifndef SOUNDAPP_AUDIOITEM_H
#define SOUNDAPP_AUDIOITEM_H
#include <string>

class Artist;

/**
 * Pure abstract base of the audio hierarchy. Carries common metadata
 * (id, name, duration, thumbnail, owners) and declares play()/pause() as pure
 * virtual so each concrete type (Song, Podcast) provides its own behavior.
 * Used as the polymorphic element type in MainPlatform::audioItems and
 * Playlist::songs.
 */
class AudioItem {
private:
    static int nextAudioItemId;     // monotonic id generator
    static int totalAudioItems;     // running count of live audio items
    int audioItemId;
    std::string audioItemName;
    int audioItemDuration;          // in seconds
    std::string audioItemThumbNailPath;
    Artist** owners;                // owned: array of co-owners
    int ownersCount;

public:

    AudioItem(std::string audioName, int audioDuration, std::string audioThumbNail, Artist** audioOwners, int ownersCount);
    virtual ~AudioItem();

    static int getTotalAudioItems();
    std::string getAudioItemName();
    int getAudioItemDuration();
    std::string getAudioItemThumbNailPath();
    int getAudioItemId();
    int getOwnersCount();
    Artist** getOwners();

    bool setAudioItemName(std::string newAudioName);

    // Pure virtual: each subclass implements its own playback behavior.
    // Called via base pointer (AudioItem*) — late binding.
    virtual void play() = 0;
    virtual void pause() = 0;
};


#endif //SOUNDAPP_AUDIOITEM_H
