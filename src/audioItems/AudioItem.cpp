#include "AudioItem.h"

#include <iostream>

using namespace std;

int AudioItem::nextAudioItemId = 1;
int AudioItem::totalAudioItems = 0;

AudioItem::AudioItem(string audioName, int audioDuration, string audioThumbNail, Artist** audioOwners) {
    this->audioItemId = AudioItem::nextAudioItemId++;
    this->audioItemName = audioName;
    this->audioItemDuration = audioDuration;
    this->audioItemThumbNailPath = audioThumbNail;
    this->owners = audioOwners;
    AudioItem::totalAudioItems++;

}

AudioItem::~AudioItem() {
    AudioItem::totalAudioItems--;
}

int AudioItem::getTotalAudioItems() {
    return AudioItem::totalAudioItems;
}

string AudioItem::getAudioItemName() {
    return this->audioItemName;
}

int AudioItem::getAudioItemId() {
    return this->audioItemId;
}

int AudioItem::getAudioItemDuration() {
    return this->audioItemDuration;
}

string AudioItem::getAudioItemThumbNailPath() {
    return this->audioItemThumbNailPath;
}

bool AudioItem::setAudioItemName(string newAudioName) {
    if (newAudioName.empty()) {
        return false;
    }
    this->audioItemName = newAudioName;
    return true;
}

void AudioItem::play() {
    cout << "Playing audio: " << this->audioItemName << endl;
}

void AudioItem::pause() {
    cout << "Pausing audio: " << this->audioItemName << endl;
}