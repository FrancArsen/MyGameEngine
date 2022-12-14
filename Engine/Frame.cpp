//
//  Frame.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/15/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Frame.h"
#include "DisplayManager.h"


namespace df{

Frame::Frame(){
    m_width = 0;
    m_height = 0;
    std::string m_frame_str;
}

Frame::Frame(int new_width, int new_height, std::string frame_str){
    m_width = new_width;
    m_height = new_height;
    m_frame_str = frame_str;
}

void Frame::setWidth(int new_width){
    m_width = new_width;
}

int Frame::getWidth() const{
    return m_width;
}

void Frame::setHeight(int new_height){
    m_height = new_height;
}

int Frame::getHeight() const{
    return m_height;
}

void Frame::setString(std::string new_frame_str){
    m_frame_str = new_frame_str;
}

std::string Frame::getString() const{
    return m_frame_str;
}

int Frame::draw(Vector position, Color color) const{
    //error check
    if(m_frame_str.empty()){
        return 0;
    }
    
    //determine x and y offset
    int x_offset = getWidth()/2;
    int y_offset = getHeight()/2;
    
    //draw character by character
    for (int y=0;y<m_height;y++){
        for (int x=0;x<m_width;x++){
            Vector temp_pos((position.getX() + x - x_offset) ,(position.getY() + y - y_offset));
            DM.drawCh(temp_pos,m_frame_str[y*m_width+x],color);
        }
    }
    return 1;
}
}
