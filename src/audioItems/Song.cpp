//
// Created by Jan Kaduch on 11.04.2026.
//

#include "Song.h"

#include <iostream>

int Song::totalSongs = 0;

Song::Song(std::string songName, int songDuration, std::string songThumbNail, Artist** songOwners, Playlist* parentAlbum)
    : AudioItem(songName, songDuration, songThumbNail, songOwners) {
    this->parentAlbum = parentAlbum;
    Song::totalSongs++;
}

Song::~Song() {
    Song::totalSongs--;
}

int Song::getTotalSongs() {
    return Song::totalSongs;
}

Playlist* Song::getParentAlbum() {
    return this->parentAlbum;
}

void Song::play() {
    // Additional logic for playing a song can be added here
    std::cout << "Playing song: " << this->getAudioItemName() << std::endl;
}

void Song::pause() {
    // Additional logic for pausing a song can be added here
    std::cout << "Pausing song: " << this->getAudioItemName() << std::endl;
}