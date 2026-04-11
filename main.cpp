#include <iostream>

#include "Artist.h"
#include "AudioItem.h"
#include "User.h"
using namespace std;

int main() {

    Artist* johnDoe = new Artist("JohnDoe", "johnDoe@email.com");
    Artist* djpicka = new Artist("DJPicka", "picka@sro.cz");

    Artist* artists[2] = { djpicka, johnDoe };
    AudioItem* a1 = new AudioItem("TestAudio", 120, "path/to/thumbnail.jpg", artists);

    a1->play();
    a1->setAudioItemName("NewName");
    a1->pause();
    cout << "Albums: "<< djpicka->getReleasedAlbums() << endl;

    delete djpicka;
    delete johnDoe;
    delete a1;
    return 0;
}