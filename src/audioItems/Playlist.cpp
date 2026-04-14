
#include "Playlist.h"
#include "AudioItem.h"
#include "User.h"

int Playlist::nextPlaylistId = 1;
int Playlist::totalPlaylists = 0;

Playlist::Playlist(std::string playlistName, User *owner) {
    this->playlistId = Playlist::nextPlaylistId++;
    this->playlistName = playlistName;
    this->songs = new AudioItem*[10]; // Initial capacity for 10 songs
    this->totalSongs = 0;
    this->playlistCapacity = 10;
    this->owner = owner;
    Playlist::totalPlaylists++;
}

Playlist::~Playlist() {
    delete[] this->songs;
    Playlist::totalPlaylists--;
}

int Playlist::getTotalPlaylists() {
    return Playlist::totalPlaylists;
}

int Playlist::getPlaylistId() {
    return this->playlistId;
}

std::string Playlist::getPlaylistName() {
    return this->playlistName;
}

int Playlist::getPlaylistCapacity() {
    return this->playlistCapacity;
}

int Playlist::getTotalSongs() {
    return this->totalSongs;
}

User *Playlist::getOwner() {
    return this->owner;
}

std::string Playlist::getPlaylistInfo() {
    std::string info = "Playlist Name: " + this->playlistName + "\n";
    info += "Created by: " + this->owner->getUsername() + "\n";
    info += "Total Songs: " + std::to_string(this->totalSongs) + "\n";
    for () {

    }
    info += "Total duration:\n";
    info += "-------------------------- \n";
    for (int i = 0; i < this->totalSongs; i++) {
        info += "Song " + std::to_string(i + 1) + ": " + this->songs[i]->getAudioItemName() + "\n";
    }
    info += "-------------------------- \n";
    return info;
}

// implement
bool Playlist::addSongToPlaylist(AudioItem* song) {

    // first check capacity if is full then increase capacity
    if (this->totalSongs >= 10) {
        return false;
    }

    // add the song to the playlist
    this->songs[this->totalSongs++] = song;
    return true;

}

// implement
bool Playlist::addSongToPlaylist(Playlist* playlist) {

    return true; // All songs added successfully
}

// implement
bool Playlist::removeSongFromPlaylist(int songId) {
    return true;
}