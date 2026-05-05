
#include "Song.h"

#include <iostream>

#include "Playlist.h"

int Song::totalSongs = 0;

Song::Song(std::string songName, int songDuration, std::string songThumbNail, Artist** songOwners, int songOwnerCount, Playlist* parentAlbum) {
    this->audioItemId = AudioItem::nextAudioItemId++;
    this->audioItemName = songName;
    this->audioItemDuration = songDuration;
    this->audioItemThumbNailPath = songThumbNail;
    this->owners = songOwners;
    this->ownersCount = songOwnerCount;
    this->parentAlbum = parentAlbum;
    AudioItem::totalAudioItems++;
    Song::totalSongs++;
}

Song::~Song() {
    delete[] this->owners;
    AudioItem::totalAudioItems--;
    Song::totalSongs--;
}

int Song::getTotalSongs() {
    return Song::totalSongs;
}

Playlist* Song::getParentAlbum() {
    return this->parentAlbum;
}

std::string Song::getAudioItemName() {
    return this->audioItemName;
}

int Song::getAudioItemDuration() {
    return this->audioItemDuration;
}

int Song::getAudioItemId() {
    return this->audioItemId;
}

std::string Song::getAudioItemThumbNailPath() {
    return this->audioItemThumbNailPath;
}

Artist** Song::getOwners() {
    return this->owners;
}

int Song::getOwnersCount() {
    return this->ownersCount;
}

bool Song::setAudioItemName(std::string newAudioName) {
    if (newAudioName.empty()) {
        return false;
    }
    this->audioItemName = newAudioName;
    return true;
}

void Song::play() {
    std::cout << "Playing song: " << this->audioItemName << std::endl;
}

void Song::pause() {
    std::cout << "Pausing song: " << this->audioItemName << std::endl;
}
