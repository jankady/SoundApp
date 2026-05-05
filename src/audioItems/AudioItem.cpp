#include "AudioItem.h"

int AudioItem::nextAudioItemId = 1;
int AudioItem::totalAudioItems = 0;

AudioItem::~AudioItem() {}

int AudioItem::getTotalAudioItems() {
    return AudioItem::totalAudioItems;
}
