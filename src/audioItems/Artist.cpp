
#include "Artist.h"
#include "User.h"
#include <iostream>

#include "MainPlatform.h"
#include "Playlist.h"
#include "Podcast.h"
#include "Song.h"

int Artist::totalArtists = 0;

// Forward base initialization to User and set up artist-specific state:
// fixed-size album pool (cap 10) and a private staging playlist.
Artist::Artist(std::string username, std::string email, MainPlatform* platform) : User(username, email, platform) {
    this->followers = 0;
    this->releasedAlbums = new Playlist *[10];
    this->releasedAlbumsCount = 0;
    this->unpublishedSongs = new Playlist("Personal", this);

    Artist::totalArtists++;
}

// Owns released albums and the staging playlist — release them here.
// Songs themselves are owned by MainPlatform, not by the artist.
Artist::~Artist() {

    for (int i = 0; i < this->releasedAlbumsCount; i++) {
        delete this->releasedAlbums[i];
    }
    delete[] this->releasedAlbums;
    delete this->unpublishedSongs;
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

// Build owners array (this artist first, then co-owners), construct the Song,
// add it to the staging playlist and register it on the platform.
Song* Artist::releaseNewSong(std::string songName, int songDuration, std::string songThumbNail, Artist** additionalOwners, int additionalOwnersCount) {

    Artist** songOwners = new Artist *[additionalOwnersCount + 1];
    songOwners[0] = this;
    for (int i = 0; additionalOwners[i] != nullptr; i++) {
        songOwners[i] = additionalOwners[i]; // Add additional owners
    }
    Song *newSong = new Song(songName, songDuration, songThumbNail, songOwners, additionalOwnersCount + 1, nullptr);
    this->unpublishedSongs->addSongToPlaylist(newSong); // Add the new song to the first album (for simplicity)
    this->getMainPlatform()->addAudioItem(newSong);
    std::cout << "Releasing new song: " << songName << std::endl;
    return newSong;
}

// Materialize a new album from everything currently in the staging playlist
// and clear the staging playlist.
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

// Build owners array (this artist first, then co-owners), construct the Podcast
// and register it on the platform. Mirrors releaseNewSong but skips the
// staging-playlist step — podcasts go live directly.
Podcast* Artist::releaseNewPodcast(std::string podcastName, int podcastDuration, std::string podcastThumbNail, Artist** additionalOwners, int additionalOwnersCount) {

    Artist** podcastOwners = new Artist *[additionalOwnersCount + 1];
    podcastOwners[0] = this;
    for (int i = 0; i < additionalOwnersCount; i++) {
        podcastOwners[i + 1] = additionalOwners[i];
    }
    Podcast* newPodcast = new Podcast(podcastName, podcastDuration, podcastThumbNail, podcastOwners, additionalOwnersCount + 1, "");
    this->getMainPlatform()->addAudioItem(newPodcast);
    std::cout << "Releasing new podcast: " << podcastName << std::endl;
    return newPodcast;
}
