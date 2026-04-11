
#include "Artist.h"
#include "User.h"
#include <iostream>

#include "Playlist.h"
#include "Song.h"

int Artist::totalArtists = 0;

Artist::Artist(std::string username, std::string email) : User(username, email) {
    this->followers = 0;
    this->releasedAlbums = new Playlist *[10];
    this->releasedAlbumsCount = 0;
    Artist::totalArtists++;
}

Artist::~Artist() {

    delete[] this->releasedAlbums;

    Artist::totalArtists--;
}

int Artist::getTotalArtists() {
    return Artist::totalArtists;
}

int Artist::getFollowers() {
    return this->followers;
}

Playlist** Artist::getReleasedAlbums() {
    return this->releasedAlbums;
}

Song* Artist::releaseNewSong(std::string songName, int songDuration, std::string songThumbNail, Artist** additionalOwners, int additionalOwnersCount) {

    Artist** songOwners = new Artist *[additionalOwnersCount + 1];
    songOwners[0] = this;
    for (int i = 0; additionalOwners[i] != nullptr; i++) {
        songOwners[i] = additionalOwners[i]; // Add additional owners
    }
    Song *newSong = new Song(songName, songDuration, songThumbNail, songOwners, additionalOwnersCount + 1, nullptr);
    this->releasedAlbums[0]->addSongToPlaylist(newSong); // Add the new song to the first album (for simplicity)
    std::cout << "Releasing new song: " << songName << std::endl;
    return newSong;
}