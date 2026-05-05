//
// Created by Jan Kaduch on 28.04.2026.
//

#ifndef SOUNDAPP_PODCAST_H
#define SOUNDAPP_PODCAST_H
#include "AudioItem.h"


/**
 * Concrete AudioItem representing a podcast episode. Carries its own copy of
 * the audio metadata (id, name, duration, thumbnail, owners) and implements
 * the full AudioItem interface. Adds a description field on top.
 */
class Podcast: public AudioItem{

private:
    static int totalPodcasts;
    int audioItemId;
    std::string audioItemName;
    int audioItemDuration;
    std::string audioItemThumbNailPath;
    Artist** owners;
    int ownersCount;
    std::string description;

public:
    Podcast(std::string podcastName, int podcastDuration, std::string podcastThumbnail, Artist** podcastOwners, int podcastOwnerCount, std::string description);
    ~Podcast() override;

    static int getTotalPodcasts();
    std::string getDescription() const;

    std::string getAudioItemName() override;
    int getAudioItemDuration() override;
    int getAudioItemId() override;
    std::string getAudioItemThumbNailPath() override;
    Artist** getOwners() override;
    int getOwnersCount() override;
    bool setAudioItemName(std::string newAudioName) override;

    void play() override;
    void pause() override;
};


#endif //SOUNDAPP_PODCAST_H
