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
)

target_include_directories(SoundApp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
)
