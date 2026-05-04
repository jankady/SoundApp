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



    delete musicApp;

    return 0;
}