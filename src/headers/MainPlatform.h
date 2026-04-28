//
// Created by Jan Kaduch on 14.04.2026.
//

#ifndef SOUNDAPP_MAINPLATFORM_H
#define SOUNDAPP_MAINPLATFORM_H
#include <string>

class User;
class AudioItem;

class MainPlatform {

private:
    User** users;
    AudioItem** audioItems;
    static int activeUsers;
    int totalAudioItems;

public:
    MainPlatform();
    ~MainPlatform();

    User* createNewUser(std::string username, std::string email, bool isArtist = false);
    AudioItem* addAudioItem(AudioItem* audioItem);
    AudioItem** getAudioItems();
    int getTotalAudioItems();

};


#endif //SOUNDAPP_MAINPLATFORM_H