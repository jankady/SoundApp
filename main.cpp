#include <iostream>

#include "Artist.h"
#include "AudioItem.h"
#include "MainPlatform.h"
#include "Playlist.h"
#include "Song.h"
#include "User.h"
using namespace std;

int main() {

    MainPlatform *musicApp = new MainPlatform();

    Artist* johnDoe = new Artist("JohnDoe", "johnDoe@email.com");
    Artist* djpicka = new Artist("DJPicka", "picka@sro.cz");

    Artist** artists = new Artist*[2];
    artists[0] = djpicka;
    artists[1] = johnDoe;
    Song* a1 = new Song("TestAudio", 120, "path/to/thumbnail.jpg", artists, 2, nullptr);

    a1->play();
    a1->setAudioItemName("NewName");
    a1->pause();
    cout << "Albums: "<< djpicka->getUnpublishedSongs()->get << endl;


    delete musicApp;
    delete djpicka;
    delete johnDoe;
    delete a1;
    return 0;
}