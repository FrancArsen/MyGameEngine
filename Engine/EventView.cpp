//
//  EventView.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/17/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "EventView.h"

namespace df{
EventView::EventView(){
    setType(VIEW_EVENT);
}

EventView::EventView(std::string new_tag, int new_value, bool new_delta){
    setType(VIEW_EVENT);
    m_tag = new_tag;
    m_value = new_value;
    m_delta = new_delta;
}

void EventView::setTag(std::string new_tag){
    m_tag = new_tag;
}

std::string EventView::getTag() const{
    return m_tag;
}

void EventView::setValue(int new_value){
    m_value = new_value;
}

int EventView::getValue() const{
    return m_value;
}

void EventView::setDelta(bool new_delta){
    m_delta = new_delta;
}

bool EventView::getDelta() const{
    return m_delta;
}
}
