//
// Created by Jan Kaduch on 14.04.2026.
//

#include "../headers/MainPlatform.h"

#include "Artist.h"
#include "AudioItem.h"
#include "Customer.h"
#include "User.h"

int MainPlatform::activeUsers = 0;

MainPlatform::MainPlatform() {

    this->users = new User*[100]; // Assuming a maximum of 100 users for
    this->audioItems = new AudioItem*[100]; // Assuming a maximum of 100 songs for simplicity
    this->totalAudioItems = 0;
    MainPlatform::activeUsers++;

}

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

User* MainPlatform::createNewUser(std::string username, std::string email, bool isArtist) {
    if (MainPlatform::activeUsers >= 100) {
        return nullptr;
    }
    User* newUser;
    if (isArtist) {
        // Create an artist user
        newUser = new Artist(username, email, this);
    }
    else {
        newUser = new Customer(username, email, this);
    }

    this->users[MainPlatform::activeUsers++] = newUser;
    return newUser;
}

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