//
//  Reticle.h
//  IMGD3000_Proj1
//
//  Created by 方申 on 1/20/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef Reticle_h
#define Reticle_h
#define RETICLE_CHAR '+'
#include "Object.h"


class Reticle : public df::Object {
    
public:
    Reticle();
    int eventHandler(const df::Event *p_e) override;
};

#endif /* Reticle_h */
