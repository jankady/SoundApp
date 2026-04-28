
#include "Artist.h"
#include "User.h"
#include <iostream>

#include "MainPlatform.h"
#include "Playlist.h"
#include "Song.h"

int Artist::totalArtists = 0;

Artist::Artist(std::string username, std::string email, MainPlatform* platform) : User(username, email) {
    this->followers = 0;
    this->releasedAlbums = new Playlist *[10];
    this->releasedAlbumsCount = 0;
    this->unpublishedSongs = new Playlist("Personal", this);
    this->platform = platform;

    Artist::totalArtists++;
}

Artist::~Artist() {

    delete[] this->releasedAlbums;
    delete[] this->unpublishedSongs;
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

Playlist* Artist::getUnpublishedSongs() {
    return this->unpublishedSongs;
}

bool Artist::addFollower() {
    this->followers++;
    return true;
}

bool Artist::removeFollower() {
    if (this->followers > 0) {
        this->followers--;
        return true;
    }
    return false;
}

Song* Artist::releaseNewSong(std::string songName, int songDuration, std::string songThumbNail, Artist** additionalOwners, int additionalOwnersCount) {

    Artist** songOwners = new Artist *[additionalOwnersCount + 1];
    songOwners[0] = this;
    for (int i = 0; additionalOwners[i] != nullptr; i++) {
        songOwners[i] = additionalOwners[i]; // Add additional owners
    }
    Song *newSong = new Song(songName, songDuration, songThumbNail, songOwners, additionalOwnersCount + 1, nullptr);
    this->unpublishedSongs->addSongToPlaylist(newSong); // Add the new song to the first album (for simplicity)
    this->platform->addAudioItem(newSong);
    std::cout << "Releasing new song: " << songName << std::endl;
    return newSong;
}

Playlist* Artist::releaseNewAlbum(std::string albumName) {
    Playlist *newAlbum = new Playlist(albumName, this);
    for (int i = 0; i < this->unpublishedSongs->getTotalSongs(); i++) {
        newAlbum->addSongToPlaylist(unpublishedSongs); // Move unpublished songs to the new album
    }
    unpublishedSongs->removeAllSongsFromPlaylist();
    this->releasedAlbums[this->releasedAlbumsCount++] = newAlbum; // Add the new album to the released albums
    std::cout << "Releasing new album: " << albumName << std::endl;
    return newAlbum;
}

// implement podcast release

