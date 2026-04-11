
#ifndef SOUNDAPP_PLAYLIST_H
#define SOUNDAPP_PLAYLIST_H
#include "AudioItem.h"


class Playlist {
private:
    static int nextPlaylistId; // Static member to generate unique playlist IDs
    static int totalPlaylists; // Static member to keep track of total playlists created
    int playlistId;
    AudioItem** songs;
    int totalSongs;
    int playlistCapacity;
    std::string playlistName;
    User *owner;

   AudioItem** incerasePlaylistCapacity();
public:
    Playlist(std::string playlistName, User *owner);
    ~Playlist();

    static int getTotalPlaylists();
    int getPlaylistId();
    int getPlaylistCapacity();
    std::string getPlaylistName();
    int getTotalSongs();
    User* getOwner();
    std::string getPlaylistInfo();

    bool addSongToPlaylist(AudioItem* song);
    bool addSongToPlaylist(Playlist* playlist);
    bool removeSongFromPlaylist(int songId);
};


#endif //SOUNDAPP_PLAYLIST_H