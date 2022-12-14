//
//  Saucer.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/2/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includes
#include "Saucer.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include "EventStep.h"
#include "EventOut.h"
#include "EventCollision.h"
#include "Vector.h"
#include "Color.h"




Saucer::Saucer() {
    setType("Saucer");
    df::Vector position(5,getId());
    df::Vector velocity(0.2,0);
    setSolidness(df::HARD);
    setPosition(position);
    setVelocity(velocity);
    setSprite("Saucer");
    getAnimation().setSlowdownCount(20);
}


int Saucer::eventHandler(const df::Event *p_e) {
    if (p_e -> getType() == df::STEP_EVENT) {
        return 1;
    }
    if (p_e -> getType() == df::COLLISION_EVENT) {
        return 1;
    }
    if (p_e -> getType() == "df::out"){
        setPosition(df::Vector(DM.getHorizontal()/2,DM.getVertical()/2));
    }
    return 0;
}

int Saucer::draw(){
    DM.drawCh(getPosition(), 'a', df::WHITE);
    DM.drawCh(getPosition() + df::Vector(1,1), 'a', df::WHITE);
    df::Object::draw();
}
