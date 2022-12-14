//
//  Manager.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/29/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//Includes
#include "Manager.h"
#include "WorldManager.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"


namespace df {

Manager::Manager() {
    
}

Manager::~Manager() {
    
}

void Manager::setType(std::string type) {
    Manager::m_type = "Manager";
}

std::string Manager::getType() const {
    return m_type;
}

int Manager::startUp() {
    m_is_started = true;
    return 0;
}

void Manager::shutDown() {
    m_is_started = false;
}

bool Manager::isStarted() const{
    return m_is_started;
}

int Manager::onEvent(const Event* p_event) const{
    int count = 0;
    ObjectList all_objects = WM.getAllObjects();
    ObjectListIterator li(&all_objects);
    while(!li.isDone())
    {
        li.currentObject()->eventHandler(p_event);
        li.next();
        count++;
    }
    return count;
}
}

