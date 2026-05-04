
#include "Song.h"

#include <iostream>

#include "Playlist.h"

int Song::totalSongs = 0;

// Forward base-class arguments to AudioItem; parentAlbum is just a back-reference.
Song::Song(std::string songName, int songDuration, std::string songThumbNail, Artist** songOwners, int songOwnerCount ,Playlist* parentAlbum)
    : AudioItem(songName, songDuration, songThumbNail, songOwners, songOwnerCount) {
    this->parentAlbum = parentAlbum;
    Song::totalSongs++;
}

Song::~Song() {
    // parentAlbum is a back-reference owned by Artist::releasedAlbums — do not delete here.
    Song::totalSongs--;
}

// Concrete implementations of AudioItem's pure virtuals — late binding entry points.

int Song::getTotalSongs() {
    return Song::totalSongs;
}

Playlist* Song::getParentAlbum() {
    return this->parentAlbum;
}

void Song::play() {
    std::cout << "Playing song: " << this->getAudioItemName() << std::endl;
}

void Song::pause() {
    std::cout << "Pausing song: " << this->getAudioItemName() << std::endl;
}