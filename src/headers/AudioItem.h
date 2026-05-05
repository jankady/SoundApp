
#ifndef SOUNDAPP_AUDIOITEM_H
#define SOUNDAPP_AUDIOITEM_H
#include <string>

class Artist;

/**
 * Pure abstract interface — no instance data, only pure virtual methods.
 * Concrete subclasses (Song, Podcast) carry the audio metadata themselves
 * and implement the full interface. Used as the polymorphic element type
 * in MainPlatform::audioItems and Playlist::songs.
 *
 * Static counters are class-scoped state (not per-instance) and are shared
 * by all concrete subclasses so that audio item ids stay globally unique.
 */
class AudioItem {
protected:
    static int nextAudioItemId;     // monotonic id generator (shared by Song/Podcast)
    static int totalAudioItems;     // running count of live audio items

public:
    virtual ~AudioItem();           // out-of-line definition required for vtable anchor

    static int getTotalAudioItems();

    virtual std::string getAudioItemName() = 0;
    virtual int getAudioItemDuration() = 0;
    virtual int getAudioItemId() = 0;
    virtual std::string getAudioItemThumbNailPath() = 0;
    virtual Artist** getOwners() = 0;
    virtual int getOwnersCount() = 0;
    virtual bool setAudioItemName(std::string newAudioName) = 0;

    virtual void play() = 0;
    virtual void pause() = 0;
};


#endif //SOUNDAPP_AUDIOITEM_H
