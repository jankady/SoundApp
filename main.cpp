#include <iostream>

#include "Artist.h"
#include "AudioItem.h"
#include "Customer.h"
#include "Date.h"
#include "Invoice.h"
#include "MainPlatform.h"
#include "Playlist.h"
#include "Podcast.h"
#include "Song.h"
#include "Subscription.h"
#include "User.h"

using namespace std;

int main() {
    cout << "=========================================\n";
    cout << "        SoundApp demo scenario\n";
    cout << "=========================================\n\n";

    // -------------------- Setup platform --------------------
    MainPlatform* spotify = new MainPlatform();

    // -------------------- Artists --------------------
    cout << "--- Creating artists ---\n";
    Artist* john    = spotify->createNewArtist("JohnDoe",  "john@email.com");
    Artist* picka   = spotify->createNewArtist("DJPicka",  "picka@sro.cz");
    Artist* madonna = spotify->createNewArtist("Madonna",  "madonna@email.com");
    Artist* eminem  = spotify->createNewArtist("Eminem",   "eminem@email.com");
    Artist* adele   = spotify->createNewArtist("Adele",    "adele@email.com");
    cout << "Total artists: " << Artist::getTotalArtists() << "\n\n";

    // -------------------- Customers --------------------
    cout << "--- Creating customers ---\n";
    Customer* alice   = spotify->createNewCustomer("Alice",   "alice@email.com");
    Customer* bob     = spotify->createNewCustomer("Bob",     "bob@email.com");
    Customer* charlie = spotify->createNewCustomer("Charlie", "charlie@email.com");
    Customer* diana   = spotify->createNewCustomer("Diana",   "diana@email.com");
    cout << "Total customers: " << Customer::getTotalCustomers() << "\n";
    cout << "Total users on platform: " << User::getTotalUsers() << "\n\n";

    // -------------------- Artists release songs --------------------
    cout << "--- Releasing songs ---\n";
    Artist* solo[] = { nullptr };
    Artist* withMadonna[] = { madonna };
    Artist* withEminem[]  = { eminem };

    john->releaseNewSong("Hello",          210, "hello.jpg",      solo, 0);
    john->releaseNewSong("World",          180, "world.jpg",      solo, 0);
    picka->releaseNewSong("Banger 2026",   240, "banger.jpg",     solo, 0);
    picka->releaseNewSong("Drop the Bass", 195, "drop.jpg",       solo, 0);
    madonna->releaseNewSong("Like a Prayer",   320, "prayer.jpg",     solo, 0);
    madonna->releaseNewSong("Material Girl",   230, "material.jpg",   solo, 0);
    eminem->releaseNewSong("Lose Yourself",    260, "lose.jpg",       withMadonna, 1);
    eminem->releaseNewSong("Stan",             400, "stan.jpg",       solo, 0);
    adele->releaseNewSong("Hello (Adele)",     295, "hello2.jpg",     solo, 0);
    adele->releaseNewSong("Rolling in the Deep", 228, "rolling.jpg",  withEminem, 1);
    cout << "Total songs released: " << Song::getTotalSongs() << "\n\n";

    // -------------------- Artists release podcasts --------------------
    cout << "--- Releasing podcasts ---\n";
    picka->releaseNewPodcast("DJ Talks",          1800, "djtalks.jpg",   solo, 0);
    madonna->releaseNewPodcast("Behind the Mic",  2400, "bts.jpg",       solo, 0);
    eminem->releaseNewPodcast("Detroit Stories",  3000, "detroit.jpg",   solo, 0);
    cout << "Total podcasts: " << Podcast::getTotalPodcasts() << "\n";
    cout << "Total audio items on platform: " << spotify->getTotalAudioItems() << "\n\n";

    // -------------------- Following --------------------
    cout << "--- Customers follow artists ---\n";
    alice->followArtist(madonna);
    alice->followArtist(eminem);
    alice->followArtist(adele);
    bob->followArtist(picka);
    bob->followArtist(madonna);
    charlie->followArtist(john);
    charlie->followArtist(eminem);
    diana->followArtist(eminem);
    diana->followArtist(adele);
    cout << "Madonna followers: " << madonna->getFollowers() << "\n";
    cout << "Eminem  followers: " << eminem->getFollowers() << "\n";
    cout << "Adele   followers: " << adele->getFollowers() << "\n";
    cout << "Picka   followers: " << picka->getFollowers() << "\n";
    cout << "John    followers: " << john->getFollowers() << "\n";

    cout << "\nBob unfollows Madonna...\n";
    bob->unfollowArtist(madonna);
    cout << "Madonna followers: " << madonna->getFollowers() << "\n\n";

    // -------------------- Customer playlists --------------------
    cout << "--- Customer playlists ---\n";
    alice->createPlaylist("Alice's Faves");
    alice->createPlaylist("Workout");
    bob->createPlaylist("Bob's Mix");
    charlie->createPlaylist("Chill");

    AudioItem** allItems = spotify->getAudioItems();
    Playlist* aliceFaves = alice->getPlaylists()[0];
    aliceFaves->addSongToPlaylist(allItems[0]); // Hello
    aliceFaves->addSongToPlaylist(allItems[4]); // Like a Prayer
    aliceFaves->addSongToPlaylist(allItems[6]); // Lose Yourself
    aliceFaves->addSongToPlaylist(allItems[9]); // Rolling in the Deep
    cout << aliceFaves->getPlaylistInfo() << "\n";

    Playlist* bobMix = bob->getPlaylists()[0];
    bobMix->addSongToPlaylist(allItems[2]); // Banger 2026
    bobMix->addSongToPlaylist(allItems[3]); // Drop the Bass
    cout << bobMix->getPlaylistInfo() << "\n";

    cout << "Total playlists in app: " << Playlist::getTotalPlaylists() << "\n";
    cout << "(includes auto-created staging playlists for each artist)\n\n";

    // -------------------- Subscriptions --------------------
    cout << "--- Subscription upgrades ---\n";
    cout << "Alice initial type: "
         << (alice->getSubscription()->getType() == PREMIUM ? "PREMIUM" : "FREE") << "\n";
    alice->getSubscription()->setSubscriptionType(PREMIUM);
    diana->getSubscription()->setSubscriptionType(PREMIUM);
    cout << "Alice after upgrade: "
         << (alice->getSubscription()->getType() == PREMIUM ? "PREMIUM" : "FREE")
         << ", active=" << alice->getSubscription()->getIsActive() << "\n";
    cout << "Diana after upgrade: "
         << (diana->getSubscription()->getType() == PREMIUM ? "PREMIUM" : "FREE")
         << ", active=" << diana->getSubscription()->getIsActive() << "\n";

    Date* aliceEnd = alice->getSubscription()->getEndDate();
    if (aliceEnd != nullptr) {
        cout << "Alice subscription ends: "
             << aliceEnd->getDay() << "/" << aliceEnd->getMonth() << "/" << aliceEnd->getYear()
             << "\n";
    }
    cout << "\n";

    // -------------------- Playback (late binding via AudioItem*) --------------------
    cout << "--- Playback (polymorphism: AudioItem* dispatches to Song/Podcast) ---\n";
    alice->setCurrentlyPlaying(allItems[0]);  // Song -> Song::play
    alice->stopPlaying();
    alice->setCurrentlyPlaying(allItems[10]); // Podcast (DJ Talks) -> Podcast::play
    alice->stopPlaying();
    bob->setCurrentlyPlaying(allItems[2]);    // Banger 2026
    bob->stopPlaying();
    cout << "\n";

    cout << "Bob searches songs containing \"Hello\":\n";
    Song** songMatches = bob->searchSong("Hello");
    for (int i = 0; songMatches[i] != nullptr; i++) {
        cout << "  - " << songMatches[i]->getAudioItemName()
             << " (" << songMatches[i]->getAudioItemDuration() << "s)\n";
    }
    delete[] songMatches;

    cout << "Charlie searches podcasts containing \"Stories\":\n";
    Podcast** podMatches = charlie->searchPodcast("Stories");
    for (int i = 0; podMatches[i] != nullptr; i++) {
        cout << "  - " << podMatches[i]->getAudioItemName()
             << " (" << podMatches[i]->getAudioItemDuration() << "s)\n";
    }
    delete[] podMatches;
    cout << "\n";

    // -------------------- Invoices --------------------
    cout << "--- Invoices for premium customers ---\n";
    Invoice* aliceInvoice = new Invoice("Alice", new Date(7, 5, 2026), 9.99);
    Invoice* dianaInvoice = new Invoice("Diana", new Date(7, 5, 2026), 9.99);
    cout << aliceInvoice->printInvoiceDetails();
    cout << aliceInvoice->getDate()->getDay() << "/"
         << aliceInvoice->getDate()->getMonth() << "/"
         << aliceInvoice->getDate()->getYear() << "  cost=$"
         << aliceInvoice->getCost() << "\n\n";
    cout << dianaInvoice->printInvoiceDetails() << "\n";

    // -------------------- Date comparison --------------------
    cout << "--- Date comparison ---\n";
    Date today(7, 5, 2026);
    Date later(31, 12, 2026);
    cout << "today.isBefore(later) = " << today.isBefore(later) << "\n";
    cout << "later.isBefore(today) = " << later.isBefore(today) << "\n\n";

    // -------------------- Late binding: printInfo() through User* --------------------
    // Grading point 7 — změna chování s pozdní vazbou:
    // User::printInfo() has a default implementation; Artist and Customer
    // override it to change behavior. Iterating MainPlatform::users (a
    // polymorphic User** array) and calling printInfo() through the base
    // pointer dispatches at runtime to the correct subclass version.
    cout << "--- printInfo() via User* (late binding) ---\n";
    User** users = spotify->getUsers();
    for (int i = 0; i < MainPlatform::getActiveUsers(); i++) {
        users[i]->printInfo();   // resolves to Artist::printInfo or Customer::printInfo
    }
    cout << "\n";

    // -------------------- Final stats --------------------
    cout << "=== Final platform stats ===\n";
    cout << "Users     : " << User::getTotalUsers()           << "\n";
    cout << "Artists   : " << Artist::getTotalArtists()       << "\n";
    cout << "Customers : " << Customer::getTotalCustomers()   << "\n";
    cout << "Songs     : " << Song::getTotalSongs()           << "\n";
    cout << "Podcasts  : " << Podcast::getTotalPodcasts()     << "\n";
    cout << "Audio items on platform: " << spotify->getTotalAudioItems() << "\n";
    cout << "Playlists : " << Playlist::getTotalPlaylists()   << "\n\n";

    // -------------------- Cleanup --------------------
    delete aliceInvoice;
    delete dianaInvoice;
    delete spotify;

    cout << "=== Demo finished cleanly ===\n";
    return 0;
}
