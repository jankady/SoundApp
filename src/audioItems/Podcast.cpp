//
// Created by Jan Kaduch on 28.04.2026.
//

#include "../headers/Podcast.h"

#include <iostream>

int Podcast::totalPodcasts = 0;

Podcast::Podcast(std::string podcastName, int podcastDuration, std::string podcastThumbnail, Artist** podcastOwners, int podcastOwnerCount, std::string description)
    : AudioItem(podcastName, podcastDuration, podcastThumbnail, podcastOwners, podcastOwnerCount) {
    this->description = description;
    Podcast::totalPodcasts++;
}

Podcast::~Podcast() {
    Podcast::totalPodcasts--;
}

int Podcast::getTotalPodcasts() {
    return Podcast::totalPodcasts;
}

std::string Podcast::getDescription() const {
    return this->description;
}

void Podcast::play() {
    std::cout << "Playing podcast: " << this->getAudioItemName() << std::endl;
}

void Podcast::pause() {
    std::cout << "Pausing podcast: " << this->getAudioItemName() << std::endl;
}