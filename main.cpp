#include <iostream>
#include "src/headers/AudioItem.h"
using namespace std;

int main() {
    AudioItem *test = new AudioItem("TestAudio", 120, "path/to/thumbnail.jpg");

    test->play();
    test->setAudioItemName("NewName");
    test->pause();

    delete test;
    return 0;
}