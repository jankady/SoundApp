//
// Created by Jan Kaduch on 11.04.2026.
//

#include "../headers/User.h"

int User::totalUsers = 0;
int User::nextUserId = 1;

User::User(std::string username, std::string email, MainPlatform* platform) {
    this->userId = User::nextUserId++;
    this->username = username;
    this->email = email;
    this->mainPlatform = mainPlatform;
    User::totalUsers++;
}

User::~User() {
    User::totalUsers--;
}

int User::getTotalUsers() {
    return User::totalUsers;
}

int User::getUserId() {
    return this->userId;
}

std::string User::getUsername() {
    return this->username;
}

std::string User::getEmail() {
    return this->email;
}

MainPlatform* User::getMainPlatform() {
    return this->mainPlatform;
}
