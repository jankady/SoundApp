
#ifndef SOUNDAPP_ARTIST_H
#define SOUNDAPP_ARTIST_H
#include <string>
#include "User.h"

class Playlist;

class Song;

class Podcast;

class MainPlatform;

class Artist: public User {
private:
    static int totalArtists; // Static member to keep track of total artists created
    int followers;
    Playlist** releasedAlbums;
    Playlist* unpublishedSongs; // Playlist to hold unpublished songs
    int releasedAlbumsCount;
    MainPlatform* platform;

public:
    Artist(std::string username, std::string email, MainPlatform* platform);
    ~Artist();

    static int getTotalArtists();

    int getFollowers();
    Playlist** getReleasedAlbums();
    Playlist* getUnpublishedSongs();

    bool addFollower();
    bool removeFollower();

    Song* releaseNewSong(std::string songName, int songDuration, std::string songThumbNail, Artist** additionalOwners, int additionalOwnersCount);
    Playlist* releaseNewAlbum(std::string albumName);
    Podcast* releaseNewPodcast(std::string podcastName, int podcastDuration, std::string podcastThumbNail, Artist** additionalOwners, int additionalOwnersCount);
};


#endif //SOUNDAPP_ARTIST_H