//
//  ViewObject.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/17/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "ViewObject.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "Utility.h"
#include "EventView.h"
#include "LogManager.h"



namespace df{
ViewObject::ViewObject(){
    
    //initialize attributes
    setSolidness(SPECTRAL);
    setAltitude(MAX_ALTITUDE);
    setType("ViewObject");
    
    setValue(0);
    setDrawValue();
    setBorder(true);
    setLocation(TOP_CENTER);
    setColor(COLOR_DEFAULT);
}

void ViewObject::setLocation(ViewObjectLocation new_location){
    Vector p;
    int y_delta = 0;
    switch(new_location){
        case TOP_LEFT:
            p.setXY(WM.getView().getHorizontal()/6,1);
            if(getBorder()== false){
                y_delta = -1;
            }
            break;
        case TOP_CENTER:
            p.setXY(WM.getView().getHorizontal()/2,1);
            if(getBorder()== false){
                y_delta = -1;
            }
            break;
        default:
            break;
    }
    p.setY(p.getY()+y_delta);
    
    setPosition(p);
    
    m_location = new_location;
}

ViewObjectLocation ViewObject::getLocation() const{
    return m_location;
}

void ViewObject::setDrawValue(bool new_draw_value){
    m_draw_value = new_draw_value;
}

bool ViewObject::getDrawValue() const{
    return m_draw_value;
}

void ViewObject::setValue(int new_value){
    m_value = new_value;
}

int ViewObject::getValue() const{
    return m_value;
}

void ViewObject::setBorder(bool new_border){
    if(m_border!= new_border){
        m_border = new_border;
        setLocation(getLocation());
    }
}

bool ViewObject::getBorder() const{
    return m_border;
}

void ViewObject::setColor(Color new_color){
    m_color = new_color;
}

Color ViewObject::getColor() const{
    return m_color;
}

void ViewObject::setViewString(std::string new_view_string){
    m_view_string = new_view_string;
}

std::string ViewObject::getViewString() const{
    return m_view_string;
}


int ViewObject::eventHandler(const Event *p_e){
    if(p_e->getType() == VIEW_EVENT){
        const EventView *p_ve = static_cast<const EventView*>(p_e);
        if (p_ve->getTag() == getViewString()) {
            if(p_ve->getDelta()){
                setValue(getValue()+p_ve->getValue());
            } else{
                setValue(p_ve->getValue());
            }
            return 1;
        }
    }
    return 0;
}

int ViewObject::draw(){
    std::string temp_str;
    if(m_border){
        temp_str = " " + getViewString() + " " + toString(m_value) + " ";
    } else{
        temp_str = getViewString() + " " + toString(m_value);
    }
    
    Vector pos = viewToWorld(getPosition());
    DM.drawString(pos, temp_str, CENTER_JUSTIFIED, getColor());
    
}

}


