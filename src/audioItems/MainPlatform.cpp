//
// Created by Jan Kaduch on 14.04.2026.
//

#include "../headers/MainPlatform.h"

#include "User.h"

int MainPlatform::activeUsers = 0;

MainPlatform::MainPlatform() {

    this->users = new User*[100]; // Assuming a maximum of 100 users for
    MainPlatform::activeUsers++;

}

MainPlatform::~MainPlatform() {
    for (int i = 0; i < this->activeUsers; i++) {
        delete this->users[i];
    }
    delete[] this->users;
}

User* MainPlatform::createNewUser(std::string username, std::string email) {
    if (this->activeUsers >= 100) {
        return nullptr;
    }
    User* newUser = new User(username, email);
    this->users[this->activeUsers++] = newUser;
    return newUser;
}
