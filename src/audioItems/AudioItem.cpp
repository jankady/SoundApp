#include "AudioItem.h"

#include <iostream>

using namespace std;

int AudioItem::nextAudioItemId = 1;
int AudioItem::totalAudioItems = 0;

AudioItem::AudioItem(string audioName, int audioDuration, string audioThumbNail, Artist** audioOwners, int ownersCount) {
    this->audioItemId = AudioItem::nextAudioItemId++;
    this->audioItemName = audioName;
    this->audioItemDuration = audioDuration;
    this->audioItemThumbNailPath = audioThumbNail;
    this->owners = audioOwners;
    this->ownersCount = ownersCount;
    AudioItem::totalAudioItems++;

}

AudioItem::~AudioItem() {
    delete[] this->owners;
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

Artist **AudioItem::getOwners() {
    return this->owners;
}

int AudioItem::getOwnersCount() {
    return this->ownersCount;
}

void AudioItem::play() {
    cout << "Playing audio: " << this->audioItemName << endl;
}

void AudioItem::pause() {
    cout << "Pausing audio: " << this->audioItemName << endl;
}