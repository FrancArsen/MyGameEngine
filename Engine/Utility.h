//
//  Utility.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/9/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef Utility_h
#define Utility_h

#include "Vector.h"
#include "Box.h"
#include <sstream>


namespace df {

//tells if two position intersects
bool positionIntersect(Vector p1, Vector p2);

//tells if two boxes collide
bool boxIntersectsBox(Box A, Box B);

//converting world position to view position
Vector worldToView(Vector world_pos);

//converting view position to world position
Vector viewToWorld(Vector world_pos);

//converting int to string
std::string toString(int i);
}


#endif /* Utility_h */
