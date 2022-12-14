//
//  WorldManager.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/2/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includes
#include "WorldManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "ObjectList.h"
#include "EventCollision.h"
#include "Utility.h"
#include "EventOut.h"
#include "Box.h"
#include "ViewObject.h"


namespace df{

WorldManager::WorldManager() {
    setType("WorldManager");

    m_updates = ObjectList();
    m_deletions = ObjectList();
}

void WorldManager::operator=(WorldManager const&) {
    
}

WorldManager & WorldManager::getInstance() {
    static WorldManager wm;
    return wm;
}

int WorldManager::startUp() {
    Manager::startUp();
    return 0;
}

void WorldManager::shutDown() {
    Manager::shutDown();
}

int WorldManager::insertObject(Object *p_o) {
    m_updates.insert(p_o);
    LM.writeLog("Object with id %i inserted",p_o->getId());
    return 0;
}

int WorldManager::removeObject(Object *p_o) {
    m_updates.remove(p_o);
    LM.writeLog("Object with id %i removed",p_o->getId());
    return 0;
}


ObjectList WorldManager::getAllObjects() const {
    return m_updates;
}

ObjectList WorldManager::objectsOfType(std::string type) const {
    ObjectListIterator iterator(&m_updates);
    ObjectList li;
    
    // select the objects with given type
    for (iterator.first(); !iterator.isDone(); iterator.next()) {
        if (iterator.currentObject()->getType() == type) {
            li.insert(iterator.currentObject());
        }
    }
    return li;
}

int WorldManager::markForDelete(Object *p_o) {
    //make sure it it not already in list
    ObjectListIterator iterator(&m_deletions);
    while (!iterator.isDone()) {
        if (iterator.currentObject() == p_o) {
            return 0;
        }
        iterator.next();
    }
    
    // put it into deletion list
    m_deletions.insert(p_o);
    return 1;
}

void WorldManager::update() {
    // delete objects in delete list
    ObjectListIterator deleteli(&m_deletions);
    while (!deleteli.isDone()) {
        delete deleteli.currentObject();
        deleteli.next();
    }
    // clear list for next update phase
    m_deletions.clear();
    
    //update object positions
    ObjectListIterator moveli(&m_updates);
    while (!moveli.isDone()) {
        //add velocity to position
        Vector new_pos = moveli.currentObject()->predictPosition();
        if(moveli.currentObject()->getPosition().getX() != new_pos.getX() || moveli.currentObject()->getPosition().getY() != new_pos.getY()){
            moveObject(moveli.currentObject(),new_pos);
        }
        moveli.next();
    }
    
}

void WorldManager::draw(){
    for(int alt=0;alt<MAX_ALTITUDE;alt++){
        ObjectListIterator iterator(&m_updates);
        while (!iterator.isDone()) {
            Object* p_temp_o = iterator.currentObject();
            if((p_temp_o->getAltitude()==alt && boxIntersectsBox(p_temp_o->getWorldBox(p_temp_o->getPosition()), getView()))|| dynamic_cast<ViewObject*>(p_temp_o)){
                p_temp_o->draw();
            }
            if(m_p_view_following == p_temp_o){
                setViewPosition(p_temp_o->getPosition());
            }
            iterator.next();
        }
        iterator.first();
    }
}

int WorldManager::moveObject(Object* p_o, Vector where){
    if (p_o->isSolid()){
        //get collision
        ObjectList list = getCollisions(p_o, where);
        if (!list.isEmpty()){
            bool do_move = true; //Assume can move

            //iterate over list
            ObjectListIterator li(&list);
            while (!li.isDone()){
                Object* p_temp_o = li.currentObject();

                //create Collision event
                EventCollision c(p_o, p_temp_o, where);

                //send to both Objects
                p_o->eventHandler(&c);
                p_temp_o->eventHandler(&c);

                //if both HARD, then cannot move
                if (p_o->getSolidness() == HARD && p_temp_o->getSolidness() == HARD){
                    do_move = false;
                }
                
                li.next();
            }
            if (do_move == false){
                return 0;
            }
        }
    }
    //if here, no collision between two HARD objects so allow move.
    Box orig_box = p_o->getBox();
    p_o->setPosition(where);
    Box new_box = p_o->getBox();
    
    //after moved, check if out of bound
    if(boxIntersectsBox(orig_box, m_boundary)&&(!boxIntersectsBox(new_box, m_boundary))){
        EventOut eo;
        p_o->eventHandler(&eo);
    }
    
    //set view following
    if(m_p_view_following == p_o){
        LM.writeLog("moving");

        setViewPosition(p_o->getPosition());
    }
    return 1;
}

ObjectList WorldManager::getCollisions(const Object *p_o, Vector where) const{
    Box b = p_o->getWorldBox(where);
    
    //make empty list
    ObjectList collision_list;
    
    //iterate through all Objects
    ObjectListIterator li(&m_updates);

    while (!li.isDone()) {
        Object* p_temp_o = li.currentObject();
        if (p_temp_o != p_o){
            Box b_temp = p_temp_o->getWorldBox(p_temp_o->getPosition());
            //same location and both solid
            if((boxIntersectsBox(b,b_temp)&& p_temp_o ->isSolid())){
                collision_list.insert(p_temp_o);
            }
        }
        li.next();
    }
    return collision_list;
}

Box WorldManager::getBoundary() const{
    return m_boundary;
}

void WorldManager::setBoundary(Box new_boundary){
    m_boundary = new_boundary;
}

Box WorldManager::getView() const{
    return m_view;
}

void WorldManager::setView(Box new_view){
    m_view = new_view;
}

int WorldManager::setViewFollowing(Object *p_new_view_following){
    //if input NULL, set to NULL
    if(p_new_view_following == NULL){
        m_p_view_following = NULL;

        return 1;
    }
    //set view following
    m_p_view_following = p_new_view_following;
    getView().setCorner(p_new_view_following->getPosition());
    
    return 1;
}

Object* WorldManager::getViewFollowing() const{
    return m_p_view_following;
}

void WorldManager::setViewPosition(Vector new_view_pos){
    //make sure horizontal not out of bound
    float x = new_view_pos.getX() - getView().getHorizontal()/2;

    if(x+getView().getHorizontal()>m_boundary.getHorizontal()){
        x = m_boundary.getHorizontal() - getView().getHorizontal();
    }

    if (x<0) x=0;
    
    //make sure vertical not out of bound
    float y = new_view_pos.getY() - getView().getVertical()/2;

    if(y+getView().getVertical()>m_boundary.getVertical()){
        y = m_boundary.getVertical() - getView().getVertical();
    }

    if (y<0) y=0;
    
    //set view
    setView(Box(Vector(x,y),getView().getHorizontal(),getView().getVertical()));

}

}
