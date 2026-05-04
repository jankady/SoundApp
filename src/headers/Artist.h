
#ifndef SOUNDAPP_ARTIST_H
#define SOUNDAPP_ARTIST_H
#include <string>
#include "User.h"

class Playlist;
class Song;
class Podcast;
class MainPlatform;

/**
 * Content-producing user. Extends User with follower count, released albums and
 * a private "unpublished" playlist used as a staging area before an album is
 * released. Provides factory-style methods that build new audio content and
 * register it with the owning MainPlatform.
 */
class Artist: public User {
private:
    static int totalArtists; // running count of live artists
    int followers;
    Playlist** releasedAlbums;     // owned: array of published albums
    Playlist* unpublishedSongs;    // owned: staging playlist for unreleased songs
    int releasedAlbumsCount;

public:
    Artist(std::string username, std::string email, MainPlatform* platform);
    ~Artist();

    static int getTotalArtists();

    int getFollowers();
    Playlist** getReleasedAlbums();
    Playlist* getUnpublishedSongs();

    bool addFollower();        // called by Customer::followArtist
    bool removeFollower();     // called by Customer::unfollowArtist

    // Build a new Song with this artist (plus any co-owners) as owner and
    // register it on the platform. Adds the song to the unpublished staging
    // playlist until releaseNewAlbum is called.
    Song* releaseNewSong(std::string songName, int songDuration, std::string songThumbNail, Artist** additionalOwners, int additionalOwnersCount);

    // Move all currently-unpublished songs into a new album playlist and
    // append it to releasedAlbums.
    Playlist* releaseNewAlbum(std::string albumName);

    // Build a new Podcast and register it on the platform.
    Podcast* releaseNewPodcast(std::string podcastName, int podcastDuration, std::string podcastThumbNail, Artist** additionalOwners, int additionalOwnersCount);
};


#endif //SOUNDAPP_ARTIST_H
