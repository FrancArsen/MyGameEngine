//
//  Music.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/17/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Music.h"
#include "LogManager.h"

namespace df{
Music::Music(){
    
}

int Music::loadMusic(std::string filename){
    sf::Music music;
    if(music.openFromFile(filename) == false){
        return 0;
    }
    m_music = &music;
    return 1;
}

void Music::setLabel(std::string new_label){
    m_label = new_label;
}

std::string Music::getLabel() const{
    return m_label;
}

void Music::play(bool loop){
    if(loop == false){
        m_music->setLoop(loop);
    }
}

void Music::stop(){
    m_music->stop();

}

void Music::pause(){
    m_music->pause();
}

sf::Music* Music::getMusic(){
    return m_music;
}
}
