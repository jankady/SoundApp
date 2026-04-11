
#ifndef SOUNDAPP_ARTIST_H
#define SOUNDAPP_ARTIST_H
#include <string>
#include "User.h"

class Playlist;

class Song;

class Artist: public User {
private:
    static int totalArtists; // Static member to keep track of total artists created
    int followers;
    Playlist** releasedAlbums;
    int releasedAlbumsCount;

public:
    Artist(std::string username, std::string email);
    ~Artist();

    static int getTotalArtists();

    int getFollowers();
    Playlist** getReleasedAlbums();

    Song* releaseNewSong(std::string songName, int songDuration, std::string songThumbNail, Artist** additionalOwners, int additionalOwnersCount);
    bool releaseNewAlbum(std::string albumName, int albumDuration, std::string albumThumbNail);
};


#endif //SOUNDAPP_ARTIST_H