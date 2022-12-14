//
// ResourceManager - The resource manager.
//
// Copyright 2017, 2019 by Mark Claypool and WPI
// All Rights Reserved
//

#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

// System includes.
#include <SFML/Audio.hpp>
#include <string>

// Engine includes.
#include "Manager.h"
#include "Sprite.h"
#include "SpriteResourceManager.h"
#include "Music.h"
#include "Sound.h"


// Two-letter acronym for easier access to manager.
#define RM df::ResourceManager::getInstance()

namespace df {

// Maximum number of unique assets in game.
const int MAX_SOUNDS = 128;
const int MAX_MUSICS = 128;

class ResourceManager : public SpriteResourceManager{
    
private:
    ResourceManager(ResourceManager const&); // Don't allow copy.
    void operator=(ResourceManager const&);  // Don't allow assignment.
    ResourceManager();		 // Private since a singleton.
    Sound m_sound[MAX_SOUNDS];     // Array of sound buffers.
    int m_sound_count;             // Count of number of loaded sounds.
    Music m_music[MAX_MUSICS];     // Array of music buffers.
    int m_music_count;             // Count of number of loaded musics.

    
public:
    // Get the one and only instance of the ResourceManager.
    static ResourceManager &getInstance();
    
    // Load sound from file.
    // Return 0 if ok, else -1.
    int loadSound(std::string filename, std::string label);

    // Remove Sound with indicated label.
    // Return 0 if ok, else -1.
    int unloadSound(std::string label);

    // Find Sound with indicated label.
    // Return pointer to it if found, else NULL.
    Sound *getSound(std::string label);

    // Associate file with Music.
    // Return 0 if ok, else -1.
    int loadMusic(std::string filename, std::string label);

    // Remove label for Music with indicated label.
    // Return 0 if ok, else -1.
    int unloadMusic(std::string label);

    // Find Music with indicated label.
    // Return pointer to it if found, else NULL.
    Music *getMusic(std::string label);
    
};

} // end of namespace df
#endif //__RESOURCE_MANAGER_H__
