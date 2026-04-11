#include <iostream>
#include "AudioItem.h"
using namespace std;

int main() {
    AudioItem test("TestAudio", 120, "path/to/thumbnail.jpg");

    test.play();
    test.setAudioItemName("NewName");
    test.pause();

    return 0;
}