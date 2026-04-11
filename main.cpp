#include <iostream>

#include "Artist.h"
#include "AudioItem.h"
#include "User.h"
using namespace std;

int main() {

    Artist* johnDoe = new Artist("JohnDoe", "johnDoe@email.com");
    cout << User::getTotalUsers() << endl; // Output: 1
    cout << johnDoe->getUsername() << endl; // Output: JohnDoe
    // AudioItem test("TestAudio", 120, "path/to/thumbnail.jpg");
    //
    // test.play();
    // test.setAudioItemName("NewName");
    // test.pause();


    delete johnDoe;
    return 0;
}