
#ifndef SOUNDAPP_ARTIST_H
#define SOUNDAPP_ARTIST_H
#include <string>


class Artist {
private:
    static int totalArtists; // Static member to keep track of total artists created
    int followers;
    Playlist* releasedAlbums;

public:
    Artist();
    ~Artist();

    static int getTotalArtists();

    int getFollowers();
    Playlist* getReleasedAlbums();

    bool releaseNewSong(std::string songName, int songDuration, std::string songThumbNail);
    bool releaseNewAlbum(std::string albumName, int albumDuration, std::string albumThumbNail);
};


#endif //SOUNDAPP_ARTIST_H