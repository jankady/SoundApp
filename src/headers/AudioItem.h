//
// Created by Jan Kaduch on 07.04.2026.
//

#ifndef SOUNDAPP_AUDIOITEM_H
#define SOUNDAPP_AUDIOITEM_H
#include <string>

using namespace std;

class AudioItem {
private:
    string audioItemName;
    int audioItemDuration; // in seconds
    string audioItemThumbNailPath;
public:

    AudioItem(string audioName, int audioDuration, string audioThumbNail);

    string getAudioItemName();
    int getAudioItemDuration();
    string getAudioItemThumbNailPath();

    bool setAudioItemName(string newAudioName);

    virtual void play();
    virtual void pause();
};


#endif //SOUNDAPP_AUDIOITEM_H