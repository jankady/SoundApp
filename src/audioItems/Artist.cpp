
#include "Artist.h"
#include "User.h"
#include <iostream>

int Artist::totalArtists = 0;

Artist::Artist(std::string username, std::string email) : User(username, email) {
    this->followers = 0;
    this->releasedAlbums = nullptr;
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

bool Artist::releaseNewSong(std::string songName, int songDuration, std::string songThumbNail) {
    // Implementation to release a new song

    std::cout << "Releasing new song: " << songName << std::endl;
    return true;
}