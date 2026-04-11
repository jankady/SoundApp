
#ifndef SOUNDAPP_AUDIOITEM_H
#define SOUNDAPP_AUDIOITEM_H
#include <string>

#include "Artist.h"

class AudioItem {
private:
    static int totalAudioItems; // Static member to keep track of total audio items created
    std::string audioItemName;
    int audioItemDuration; // in seconds
    std::string audioItemThumbNailPath;
    Artist* owner;

public:

    AudioItem(std::string audioName, int audioDuration, std::string audioThumbNail);
    virtual ~AudioItem();

    static int getTotalAudioItems();
    std::string getAudioItemName();
    int getAudioItemDuration();
    std::string getAudioItemThumbNailPath();

    bool setAudioItemName(std::string newAudioName);

    virtual void play();
    virtual void pause();
};


#endif //SOUNDAPP_AUDIOITEM_H