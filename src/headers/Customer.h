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

class Customer: public User{
private:
    static int totalCustomers; // Static member to keep track of total customers created
    Playlist** playlists;
    Subscription* subscription;
    Artist**  followingArtists;
    int totalPlaylists;
    int followingArtistsCount;
    AudioItem* currentlyPlaying;

public:
    Customer(std::string username, std::string email);
    virtual ~Customer() override;
    static int getTotalCustomers();

    Playlist** getPlaylists();
    Subscription* getSubscription();
    Artist** getFollowingArtists();


    bool followArtist(Artist* artist);
    Song** searchSong(std::string songName);
    Podcast** searchPodcast(std::string podcastName);
    bool createPlaylist(std::string playlistName);
};


#endif //SOUNDAPP_CUSTOMER_H