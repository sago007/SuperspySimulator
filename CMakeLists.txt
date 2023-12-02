cmake_minimum_required(VERSION 3.5.1...3.27.4)
project (SuperspySimulator)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SuperspySimulator_SOURCE_DIR}/Extra/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-sign-compare -Wsuggest-override -Wno-unused-parameter -std=c++17 -g")

#Setup SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#Setup things that use pkg-config
find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf)

file(GLOB SOURCES "Platformer/*.cpp" "Platformer/Libs/*.cpp")


add_executable(SuperspySimulator ${SOURCES})
target_link_libraries( SuperspySimulator PRIVATE ${SDL2_LIBRARY} stdc++fs m)
target_link_libraries( SuperspySimulator PRIVATE ${SDL2MIXER_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES})
target_link_libraries( SuperspySimulator PRIVATE physfs)
