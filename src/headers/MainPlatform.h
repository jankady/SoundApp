//
// Created by Jan Kaduch on 14.04.2026.
//

#ifndef SOUNDAPP_MAINPLATFORM_H
#define SOUNDAPP_MAINPLATFORM_H
#include <string>

class User;

class MainPlatform {

private:
    User** users;
    static int activeUsers;

public:
    MainPlatform();
    ~MainPlatform();

    User* createNewUser(std::string username, std::string email);
};


#endif //SOUNDAPP_MAINPLATFORM_H