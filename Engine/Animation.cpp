//
//  Animation.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/16/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Animation.h"

namespace df{
Animation::Animation(){
    m_index = 1;
    m_slowdown_count = 10;
}

void Animation::setSprite(Sprite *p_new_sprite){
    m_p_sprite = p_new_sprite;
}

Sprite* Animation::getSprite() const{
    return m_p_sprite;
}

void Animation::setName(std::string new_name){
    m_name = new_name;
}

std::string Animation::getName() const{
    return m_name;
}

void Animation::setIndex(int new_index){
    m_index = new_index;
}

int Animation::getIndex() const{
    return m_index;
}

void Animation::setSlowdownCount(int new_slowdown_count){
    m_slowdown_count = new_slowdown_count;
}

int Animation::getSlowdownCount() const{
    return m_slowdown_count;
}

int Animation::draw(Vector position){
    // if no sprite, return 0
    if(m_p_sprite == NULL){
        return 0;
    }
    
    //ask sprite to draw
    int index = getIndex();
    m_p_sprite->draw(index, position);
    
    //check slowdown, if -1, animation frozen
    if(getSlowdownCount() == -1){
        return 0;
    }
    
    //increment counter
    int count = getSlowdownCount();
    count++;
    
    //advance index, if appropriate
    if(count>=getSlowdownCount()){
        count = 0;//reset counter
        index++;//advance frame
        
        //if last frame, loop to begining
        if (index>= m_p_sprite->getFrameCount()){
            index = 0;
        }
        
        //set index for new draw
        setIndex(index);
    }
    
    //set counter for next draw
    setSlowdownCount(count);
}

Box Animation::getBox() const{
    //if no sprite, return unit Box centered at (0,0)
    if(m_p_sprite == NULL){
        Box box(Vector(-0.5,-0.5),0.99,0.99);
        return box;
    }
    
    //create box around centered Sprite
    Vector corner(-1*m_p_sprite->getWidth()/2.0,-1*m_p_sprite->getHeight()/2.0);
    Box box(corner, m_p_sprite->getWidth(),m_p_sprite->getHeight());
    
    return box;
}


}
