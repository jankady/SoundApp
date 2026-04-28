
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

    virtual void play() = 0; // Pure virtual function to be implemented by derived classes
    virtual void pause() = 0;
};


#endif //SOUNDAPP_AUDIOITEM_H