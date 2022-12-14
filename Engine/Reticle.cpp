//
//  Reticle.cpp
//  IMGD3000_Proj1
//
//  Created by 方申 on 1/20/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include <stdio.h>
#include "Reticle.h"
#include "Reticle.h"
#include "EventMouse.h"
#include "DisplayManager.h"
#include "WorldManager.h"


Reticle::Reticle() {
    // Setting the type to Reticle
    setType("Reticle");
    
    // Setting the solidness so it wont collide
    setSolidness(df::SPECTRAL);
    
    // setting the altitude to top
    setAltitude(df::MAX_ALTITUDE);
        
    // Start reticle in center of window.
    df::Vector p(DM.getHorizontal()/2,
                 DM.getVertical()/2);
    setPosition(p);
}

// Handle event.
// Return 0 if ignored, else 1.
int Reticle::eventHandler(const df::Event *p_e) {
    
    if (p_e->getType() == df::MSE_EVENT) {
        const df::EventMouse *p_mouse_event =
        dynamic_cast <const df::EventMouse *> (p_e);
        if (p_mouse_event->getMouseAction() == df::MOVED) {
            // Change location to new mouse position.
            setPosition(p_mouse_event->getMousePosition());
            return 1;
        }
    }
    
    // If get here, have ignored this event.
    return 0;
}

