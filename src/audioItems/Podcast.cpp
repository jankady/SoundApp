//
// Created by Jan Kaduch on 28.04.2026.
//

#include "../headers/Podcast.h"

#include <iostream>

int Podcast::totalPodcasts = 0;

Podcast::Podcast(std::string podcastName, int podcastDuration, std::string podcastThumbnail, Artist** podcastOwners, int podcastOwnerCount, std::string description) {
    this->audioItemId = AudioItem::nextAudioItemId++;
    this->audioItemName = podcastName;
    this->audioItemDuration = podcastDuration;
    this->audioItemThumbNailPath = podcastThumbnail;
    this->owners = podcastOwners;
    this->ownersCount = podcastOwnerCount;
    this->description = description;
    AudioItem::totalAudioItems++;
    Podcast::totalPodcasts++;
}

Podcast::~Podcast() {
    delete[] this->owners;
    AudioItem::totalAudioItems--;
    Podcast::totalPodcasts--;
}

int Podcast::getTotalPodcasts() {
    return Podcast::totalPodcasts;
}

std::string Podcast::getDescription() const {
    return this->description;
}

std::string Podcast::getAudioItemName() {
    return this->audioItemName;
}

int Podcast::getAudioItemDuration() {
    return this->audioItemDuration;
}

int Podcast::getAudioItemId() {
    return this->audioItemId;
}

std::string Podcast::getAudioItemThumbNailPath() {
    return this->audioItemThumbNailPath;
}

Artist** Podcast::getOwners() {
    return this->owners;
}

int Podcast::getOwnersCount() {
    return this->ownersCount;
}

bool Podcast::setAudioItemName(std::string newAudioName) {
    if (newAudioName.empty()) {
        return false;
    }
    this->audioItemName = newAudioName;
    return true;
}

void Podcast::play() {
    std::cout << "Playing podcast: " << this->audioItemName << std::endl;
}

void Podcast::pause() {
    std::cout << "Pausing podcast: " << this->audioItemName << std::endl;
}
