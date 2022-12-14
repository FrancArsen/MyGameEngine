//
//  Sound.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/17/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Sound.h"
#include "LogManager.h"
#include <SFML/Audio.hpp>


namespace df{
Sound::Sound(){
    
}

Sound::~Sound(){
    
}

int Sound::loadSound(std::string filename){
    //load from file
    sf::SoundBuffer buffer;
    if (buffer.loadFromFile(filename) == false){
        return 0;
    }
    m_sound_buffer = buffer;
    
    //load sound
    sf::Sound sound;
    sound.setBuffer(buffer);
    m_sound = sound;
    
    return 1;
}
void Sound::setLabel(std::string new_label){
    m_label = new_label;
}

std::string Sound::getLabel() const{
    return m_label;
}

void Sound::play(bool loop){
    if(loop == true){
        m_sound.setLoop(loop);
    }
    m_sound.play();
}

void Sound::stop(){
    m_sound.stop();
}

void Sound::pause(){
    m_sound.pause();
}
sf::Sound Sound::getSound() const{
    return m_sound;
}
}

