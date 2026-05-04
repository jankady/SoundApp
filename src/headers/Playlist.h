
#ifndef SOUNDAPP_PLAYLIST_H
#define SOUNDAPP_PLAYLIST_H
#include <string>

class AudioItem;
class User;

/**
 * Ordered collection of audio items (Songs and Podcasts via the AudioItem
 * polymorphic base). Used both as a customer's playlist and as an artist's
 * album / staging area. Stores AudioItem* pointers but does NOT own them —
 * lifetimes are managed by MainPlatform.
 */
class Playlist {
private:
    static int nextPlaylistId;     // monotonic id generator
    static int totalPlaylists;     // running count of live playlists
    int playlistId;
    AudioItem** songs;             // not owned, polymorphic array
    int totalSongs;
    int playlistCapacity;
    std::string playlistName;
    User *owner;
public:
    Playlist(std::string playlistName, User *owner);
    ~Playlist();

    static int getTotalPlaylists();
    int getPlaylistId();
    int getPlaylistCapacity();
    std::string getPlaylistName();
    int getTotalSongs();
    User* getOwner();

    // Multi-line summary: name, owner, total songs, total duration, list.
    std::string getPlaylistInfo();

    // Overloaded: append a single audio item, or append all items from
    // another playlist.
    bool addSongToPlaylist(AudioItem* song);
    bool addSongToPlaylist(Playlist* playlist);

    bool removeSongFromPlaylist(int songId);
    bool removeAllSongsFromPlaylist();

};


#endif //SOUNDAPP_PLAYLIST_H
