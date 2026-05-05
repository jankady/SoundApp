//
// Created by Jan Kaduch on 14.04.2026.
//

#ifndef SOUNDAPP_MAINPLATFORM_H
#define SOUNDAPP_MAINPLATFORM_H
#include <string>

class User;
class Artist;
class Customer;
class AudioItem;

/**
 * Root aggregate of the application. Owns and manages the lifetimes of all
 * users (User**, polymorphic — Artist or Customer) and all audio items
 * (AudioItem**, polymorphic — Song or Podcast). Exposes factory methods that
 * construct concrete types and store them upcast in the polymorphic arrays.
 */
class MainPlatform {

private:
    User** users;                  // owned: polymorphic array of users
    AudioItem** audioItems;        // owned: polymorphic array of audio content
    static int activeUsers;        // shared count across platform instances
    int totalAudioItems;

public:
    MainPlatform();
    ~MainPlatform();

    // Factory methods. Concrete return type (Artist*/Customer*) makes the
    // call site type-safe; the pointer is also stored upcast in users[].
    Artist* createNewArtist(std::string username, std::string email);
    Customer* createNewCustomer(std::string username, std::string email);

    // Register an audio item (called by Artist::releaseNewSong / releaseNewPodcast).
    AudioItem* addAudioItem(AudioItem* audioItem);

    AudioItem** getAudioItems();
    int getTotalAudioItems();

    // Expose the polymorphic User** array so callers can iterate and invoke
    // virtual methods (e.g. printInfo) through the base pointer — this is
    // where late binding is observable from main.
    User** getUsers();
    static int getActiveUsers();

};


#endif //SOUNDAPP_MAINPLATFORM_H
