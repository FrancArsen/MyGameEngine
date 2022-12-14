//
//  Hero.h
//  IMGD3000_Proj1
//
//  Created by 方申 on 1/20/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef Hero_h
#define Hero_h
#include "Object.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "Reticle.h"


class Hero : public df::Object {
    
private:
    int move_slowdown;
    int move_countdown;
    int fire_slowdown;
    int fire_countdown;
    int nukecount;
    Reticle *p_reticle;
    void kbd(const df::EventKeyboard *p_keyboard_event);
    void move(int dy);
public:
    Hero();
    ~Hero();
    int eventHandler(const df::Event *p_e) override;
    int draw() override;
};


#endif /* Hero_h */
