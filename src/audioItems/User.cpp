//
// Created by Jan Kaduch on 11.04.2026.
//

#include "../headers/User.h"

#include <iostream>

int User::totalUsers = 0;
int User::nextUserId = 1;

// Assign a fresh id from the static counter and store the platform back-pointer.
User::User(std::string username, std::string email, MainPlatform* platform) {
    this->userId = User::nextUserId++;
    this->username = username;
    this->email = email;
    this->mainPlatform = platform;
    User::totalUsers++;
}

// Virtual — invoked through User* base pointer in MainPlatform::~MainPlatform.
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

// Default behavior — prints generic identity. Artist/Customer override this
// to extend the output with role-specific information.
void User::printInfo() {
    std::cout << "[User] id=" << this->userId
              << ", username=" << this->username
              << ", email=" << this->email << std::endl;
}
