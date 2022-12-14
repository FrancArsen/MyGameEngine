//
//  Hero.cpp
//  IMGD3000_Proj1
//
//  Created by 方申 on 1/20/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Hero.h"

#include "WorldManager.h"
#include "GameManager.h"
#include "EventStep.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "LogManager.h"
#include "DisplayManager.h"




Hero::Hero() {
    
    // Setting the type and location to left edge
    setType("Hero");
    df::Vector p(7, DM.getVertical()/2);
    setPosition(p);
    
    // Create reticle for firing bullets and aiming.
    p_reticle = new Reticle();
    p_reticle->draw();
    
    // Slow down the movement speed
    move_slowdown = 2;
    move_countdown = move_slowdown;
    
    // Slow down the fire speed
    fire_slowdown = 15;
    fire_countdown = fire_slowdown;
    
    nukecount = 2;
    
}

//Set gameover after hero removed
Hero::~Hero() {

}

//handles an kbd event
int Hero::eventHandler(const df::Event *p_e) {
    
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        const df::EventKeyboard *p_keyboard_event = dynamic_cast <const df::EventKeyboard *> (p_e);
        kbd(p_keyboard_event);
        return 1;
    }
    
    // If get here, have ignored this event.
    return 0;
}


// Take appropriate action according to key pressed.
void Hero::kbd(const df::EventKeyboard *p_keyboard_event) {
    
    switch(p_keyboard_event->getKey()) {
            
        case df::Keyboard::UPARROW:    // down
                move(+1);
            break;
        case df::Keyboard::DOWNARROW:    // up
                move(-1);
        default:    // Key not included
            return;
    };
}


// Move up or down.
void Hero::move(int dy) {
    
    // If stays on window, allow move.
    df::Vector new_pos(getPosition().getX(), getPosition().getY() + dy);
    setPosition(new_pos);
}

int Hero::draw(){
    DM.drawCh(getPosition(),'*', df::WHITE);
}
