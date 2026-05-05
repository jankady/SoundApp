//
// Created by Jan Kaduch on 21.04.2026.
//

#ifndef SOUNDAPP_CUSTOMER_H
#define SOUNDAPP_CUSTOMER_H
#include "Subscription.h"
#include "User.h"

class User;
class Playlist;
class Subscription;
class Artist;
class Song;
class AudioItem;
class Podcast;
class MainPlatform;

/**
 * Content-consuming user. Extends User with personal playlists, a subscription,
 * a list of followed artists and the currently playing item. Search methods
 * walk the platform's polymorphic AudioItem array and use dynamic_cast to
 * filter by concrete type.
 */
class Customer: public User{
private:
    static int totalCustomers; // running count of live customers
    Playlist** playlists;            // owned: customer's own playlists
    Subscription* subscription;      // owned: FREE by default
    Artist**  followingArtists;      // not owned: pointers into MainPlatform
    int totalPlaylists;
    int followingArtistsCount;
    AudioItem* currentlyPlaying;     // not owned: pointer into MainPlatform
public:
    Customer(std::string username, std::string email, MainPlatform* platform);
    virtual ~Customer() override;
    static int getTotalCustomers();

    Playlist** getPlaylists();
    Subscription* getSubscription();
    Artist** getFollowingArtists();
    AudioItem* getCurrentlyPlaying();

    // Set currentlyPlaying and call play() on it (late binding to Song/Podcast).
    bool setCurrentlyPlaying(AudioItem* audioItem);
    // Call pause() on the current item and clear it.
    bool stopPlaying();

    bool followArtist(Artist* artist);
    bool unfollowArtist(Artist* artist);

    // Linear-scan the platform's AudioItem array, dynamic_cast to the
    // concrete type and return a null-terminated array of matches by name.
    Song** searchSong(std::string songName);
    Podcast** searchPodcast(std::string podcastName);

    bool createPlaylist(std::string playlistName);

    // Override changes the behavior inherited from User: identifies the user
    // as a Customer and adds subscription tier + playlist count + followed
    // artists count to the output. Resolved via late binding when called
    // through User*.
    virtual void printInfo() override;
};


#endif //SOUNDAPP_CUSTOMER_H
