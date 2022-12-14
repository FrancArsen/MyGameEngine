//
//  Saucer.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/2/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef Saucer_h
#define Saucer_h

#include "Object.h"

class Saucer : public df::Object{
    
public:
    // Default constructor
    Saucer();
    
    // Handles events, return 1 if consumed
    int eventHandler(const df::Event * p_e) override;
    
    int draw() override;
};

#endif /* Saucer_h */
