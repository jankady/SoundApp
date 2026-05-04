//
// Created by Jan Kaduch on 28.04.2026.
//

#ifndef SOUNDAPP_PODCAST_H
#define SOUNDAPP_PODCAST_H
#include "AudioItem.h"


/**
 * Concrete AudioItem representing a podcast episode. Extends AudioItem with a
 * description string. Implements play()/pause() with simple console output to
 * demonstrate late binding via AudioItem*.
 */
class Podcast: public AudioItem{

private:
    static int totalPodcasts;      // running count of live podcasts
    std::string description;

public:
    Podcast(std::string podcastName, int podcastDuration, std::string podcastThumbnail, Artist** podcastOwners, int podcastOwnerCount, std::string description);
    ~Podcast() override;

    static int getTotalPodcasts();
    std::string getDescription() const;

    void play() override;          // overrides pure virtual AudioItem::play
    void pause() override;

};


#endif //SOUNDAPP_PODCAST_H
