//
// Created by Jan Kaduch on 28.04.2026.
//

#ifndef SOUNDAPP_PODCAST_H
#define SOUNDAPP_PODCAST_H
#include "AudioItem.h"


class Podcast: public AudioItem{

private:
    static int totalPodcasts; // Static member to keep track of total podcasts created
    std::string description;

public:
    Podcast(std::string podcastName, int podcastDuration, std::string podcastThumbnail, Artist** podcastOwners, int podcastOwnerCount, std::string description);
    ~Podcast() override;

    static int getTotalPodcasts();
    std::string getDescription() const;
    void play() override;
    void pause() override;

};


#endif //SOUNDAPP_PODCAST_H