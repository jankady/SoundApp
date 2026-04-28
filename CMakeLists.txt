cmake_minimum_required(VERSION 3.20)
project(SoundApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoundApp
        main.cpp
        src/audioItems/AudioItem.cpp
        src/headers/AudioItem.h
        src/audioItems/Artist.cpp
        src/headers/Artist.h
        src/audioItems/Playlist.cpp
        src/headers/Playlist.h
        src/audioItems/User.cpp
        src/headers/User.h
        src/audioItems/Song.cpp
        src/headers/Song.h
        src/audioItems/MainPlatform.cpp
        src/headers/MainPlatform.h
        src/audioItems/Customer.cpp
        src/headers/Customer.h
        src/audioItems/Subscription.cpp
        src/headers/Subscription.h
        src/audioItems/Invoice.cpp
        src/headers/Invoice.h
        src/audioItems/Date.cpp
        src/headers/Date.h
        src/audioItems/Podcast.cpp
        src/headers/Podcast.h
)

target_include_directories(SoundApp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
)
