#include <iostream>

#include "Artist.h"
#include "Customer.h"
#include "Date.h"
#include "MainPlatform.h"

using namespace std;

static Date* currentDay = new Date(7,4,2026);

int main() {

    MainPlatform *musicApp = new MainPlatform();
    Artist* john = musicApp->createNewArtist("JohnDoe", "johnDoe@email.com");
    Artist* djpicka = musicApp->createNewArtist("DJPicka", "picka@sro.cz");
    Customer* alice = musicApp->createNewCustomer("Alice", "alice@email.com");




    // Artist* johnDoe = new Artist();
    // Artist* djpicka = new Artist();
    //
    // Artist** artists = new Artist*[2];
    // artists[0] = djpicka;
    // artists[1] = johnDoe;
    // Song* a1 = new Song("TestAudio", 120, "path/to/thumbnail.jpg", artists, 2, nullptr);
    //
    // a1->play();
    // a1->setAudioItemName("NewName");


    delete musicApp;

    return 0;
}