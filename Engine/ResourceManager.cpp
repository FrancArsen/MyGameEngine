//
//  ResourceManager.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/15/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "ResourceManager.h"
#include "LogManager.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"


namespace df{
ResourceManager::ResourceManager() {
    setType("ResourceManager");
    m_sound_count = 0;
    m_music_count = 0;
    *p_sprite = new Sprite[MAX_SPRITES];
    m_sprite_count = 0;
}

void ResourceManager::operator=(ResourceManager const&) {
    
}

ResourceManager & ResourceManager::getInstance() {
    static ResourceManager rm;
    return rm;
}

int ResourceManager::loadSound(std::string filename, std::string label){
    if(m_sound_count >=MAX_SOUNDS){
        LM.writeLog("sound array full");
        return 0;
    }
    
    if(m_sound[m_sound_count].loadSound(filename) == 0){
        LM.writeLog("Unable to load sound");
        return 0;
    }
    
    m_sound[m_sound_count].setLabel(label);
    m_sound_count++;
    return 1;
}

int ResourceManager::unloadSound(std::string label){
    for(int i=0;i<m_sound_count;i++){
        if(label == m_sound[i].getLabel()){
            //scoot over remaining sound
            for(int j=i;j<m_sound_count-1;j++){
                m_sound[j] = m_sound[j+1];
            }
            m_sound_count--;
            return 1;
        }
    }
    return 0;
}

Sound* ResourceManager::getSound(std::string label){
    for(int i=0;i<m_sound_count;i++){
        if(label == m_sound[i].getLabel()){
            return &m_sound[i];
        }
    }
    return NULL;
}

int ResourceManager::loadMusic(std::string filename, std::string label){
    if(m_music_count >=MAX_MUSICS){
        LM.writeLog("music array full");
        return 0;
    }
    
    if(m_music[m_music_count].loadMusic(filename) == 0){
        LM.writeLog("Unable to load music");
        return 0;
    }
    
    m_music[m_music_count].setLabel(label);
    m_music_count++;
    return 1;
}

int ResourceManager::unloadMusic(std::string label){
    for(int i=0;i<m_music_count;i++){
        if(label == m_music[i].getLabel()){
            m_music[i].setLabel("");
            m_music_count--;
            return 1;
        }
    }
    return 0;
}

Music* ResourceManager::getMusic(std::string label){
    if(label == ""){
        return NULL;
    }
    for(int i=0;i<m_music_count;i++){
        if(label == m_music[i].getLabel()){
            return &m_music[i];
        }
    }
    return NULL;
}
}
