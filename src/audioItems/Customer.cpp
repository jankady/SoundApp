//
// Created by Jan Kaduch on 21.04.2026.
//

#include "../headers/Customer.h"

#include "Artist.h"
#include "Playlist.h"

int Customer::totalCustomers = 0;

Customer::Customer(std::string username, std::string email) : User(username, email) {
    this->playlists = new Playlist*[10]; // Initial capacity for 10 playlists
    this->totalPlaylists = 0;
    this->subscription = new Subscription(FREE); // Default subscription is FREE
    this->followingArtists = new Artist*[10]; // Initial capacity for 10 followed artists
    this->followingArtistsCount = 0;
    this->currentlyPlaying = nullptr;
    Customer::totalCustomers++;
}

Customer::~Customer() {
    for (int i = 0; i < this->totalPlaylists; i++) {
        delete this->playlists[i];
    }
    delete[] this->playlists;
    delete this->subscription;
    for (int i = 0; i < this->followingArtistsCount; i++) {
        delete this->followingArtists[i];
    }
    delete[] this->followingArtists;
    Customer::totalCustomers--;
}

int Customer::getTotalCustomers() {
    return Customer::totalCustomers;
}

Playlist **Customer::getPlaylists() {
    return this->playlists;
}

Subscription *Customer::getSubscription() {
    return this->subscription;
}

Artist **Customer::getFollowingArtists() {
    return this->followingArtists;
}

bool Customer::followArtist(Artist *artist) {
    if (this->followingArtistsCount >= 10) {
        return false; // Cannot follow more than 10 artists
    }
    this->followingArtists[this->followingArtistsCount++] = artist;
    artist->addFollower(); // Increment the follower count of the artist
    return true;
}

bool Customer::unfollowArtist(Artist *artist) {
    for (int i = 0; i < this->followingArtistsCount; i++) {
        if (this->followingArtists[i] == artist) {
            // Shift remaining artists to fill the gap
            for (int j = i; j < this->followingArtistsCount - 1; j++) {
                this->followingArtists[j] = this->followingArtists[j + 1];
            }
            this->followingArtists[--this->followingArtistsCount] = nullptr; // Decrease count and set last to nullptr
            artist->removeFollower(); // Decrement the follower count of the artist
            return true;
        }
    }
    return false; // Artist not found in following list
}

Song** Customer::searchSong(std::string songName) {

    for ()
    return nullptr;
}