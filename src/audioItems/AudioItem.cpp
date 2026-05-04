#include "AudioItem.h"

#include <iostream>

using namespace std;

int AudioItem::nextAudioItemId = 1;
int AudioItem::totalAudioItems = 0;

// Take ownership of the owners array allocated by the caller (Artist::releaseNew*).
AudioItem::AudioItem(string audioName, int audioDuration, string audioThumbNail, Artist** audioOwners, int ownersCount) {
    this->audioItemId = AudioItem::nextAudioItemId++;
    this->audioItemName = audioName;
    this->audioItemDuration = audioDuration;
    this->audioItemThumbNailPath = audioThumbNail;
    this->owners = audioOwners;
    this->ownersCount = ownersCount;
    AudioItem::totalAudioItems++;

}

// Virtual — invoked through AudioItem* base pointer in MainPlatform's destructor.
// Frees the owners array but not the Artist objects (those belong to MainPlatform).
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
