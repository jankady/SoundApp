cmake_minimum_required(VERSION 3.20)
project(SoundApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoundApp
        main.cpp
        src/audioItems/AudioItem.cpp
        src/audioItems/Artist.cpp
        src/audioItems/Playlist.cpp
        )

target_include_directories(SoundApp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
)
