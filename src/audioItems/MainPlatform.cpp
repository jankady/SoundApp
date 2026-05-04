//
// Created by Jan Kaduch on 14.04.2026.
//

#include "../headers/MainPlatform.h"

#include "Artist.h"
#include "AudioItem.h"
#include "Customer.h"
#include "User.h"

int MainPlatform::activeUsers = 0;

// Pre-allocate fixed-size pools for users and audio items.
MainPlatform::MainPlatform() {

    this->users = new User*[100]; // Assuming a maximum of 100 users for
    this->audioItems = new AudioItem*[100]; // Assuming a maximum of 100 songs for simplicity
    this->totalAudioItems = 0;

}

// Owner of all users and audio items: delete each pointee polymorphically
// (User and AudioItem have virtual destructors), then free the arrays.
MainPlatform::~MainPlatform() {
    for (int i = 0; i < MainPlatform::activeUsers; i++) {
        delete this->users[i];
    }
    delete[] this->users;
    for (int i = 0; i < this->totalAudioItems; i++) {
        delete this->audioItems[i];
    }
    delete[] this->audioItems;
}

// Factory: build a concrete Artist, store it upcast in users[] (polymorphic
// data structure), and return the precise type to the caller.
Artist* MainPlatform::createNewArtist(std::string username, std::string email) {
    if (MainPlatform::activeUsers >= 100) {
        return nullptr;
    }
    Artist* newArtist = new Artist(username, email, this);
    this->users[MainPlatform::activeUsers++] = newArtist;
    return newArtist;
}

// Same pattern as createNewArtist but for the Customer subclass.
Customer* MainPlatform::createNewCustomer(std::string username, std::string email) {
    if (MainPlatform::activeUsers >= 100) {
        return nullptr;
    }
    Customer* newCustomer = new Customer(username, email, this);
    this->users[MainPlatform::activeUsers++] = newCustomer;
    return newCustomer;
}

// Called by Artist::releaseNew* when a new piece of content goes live.
AudioItem* MainPlatform::addAudioItem(AudioItem* audioItem) {
    if (this->totalAudioItems >= 100) {
        return nullptr; // Cannot add more than 100 audio items
    }
    this->audioItems[this->totalAudioItems++] = audioItem;
    return audioItem;
}

AudioItem** MainPlatform::getAudioItems() {
    return this->audioItems;
}

int MainPlatform::getTotalAudioItems() {
    return this->totalAudioItems;
}