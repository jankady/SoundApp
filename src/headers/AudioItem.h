
#ifndef SOUNDAPP_AUDIOITEM_H
#define SOUNDAPP_AUDIOITEM_H
#include <string>

class Artist;

class AudioItem {
private:
    static int nextAudioItemId; // Static member to generate unique audio item IDs
    static int totalAudioItems; // Static member to keep track of total audio items created
    int audioItemId;
    std::string audioItemName;
    int audioItemDuration; // in seconds
    std::string audioItemThumbNailPath;
    Artist** owners;

public:

    AudioItem(std::string audioName, int audioDuration, std::string audioThumbNail, Artist** audioOwners);
    virtual ~AudioItem();

    static int getTotalAudioItems();
    std::string getAudioItemName();
    int getAudioItemDuration();
    std::string getAudioItemThumbNailPath();
    int getAudioItemId();

    bool setAudioItemName(std::string newAudioName);

    virtual void play();
    virtual void pause();
};


#endif //SOUNDAPP_AUDIOITEM_H