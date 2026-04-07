//
// Created by Jan Kaduch on 07.04.2026.
//

#include "../headers/AudioItem.h"

#include <iostream>

using namespace std;

AudioItem::AudioItem(string audioName, int audioDuration, string audioThumbNail) {
    this->audioItemName = audioName;
    this->audioItemDuration = audioDuration;
    this->audioItemThumbNailPath = audioThumbNail;
}

string AudioItem::getAudioItemName() {
    return this->audioItemName;
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