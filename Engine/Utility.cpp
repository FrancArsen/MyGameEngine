//
//  Utility.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/9/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Vector.h"
#include "Box.h"
#include "WorldManager.h"
#include <sstream>
#include <string>
#include <cmath>

namespace df{
bool positionIntersect(Vector p1, Vector p2){
    if (abs(p1.getX() - p2.getX())<=1 && abs(p1.getY() - p2.getY())<=1){
        return true;
    }
    return false;
}

bool boxIntersectsBox(Box A, Box B){
    //tells if the x-side of boxes ovelap
    bool x_overlap = ((B.getCorner().getX()<=A.getCorner().getX()+A.getHorizontal()) && (B.getCorner().getX()>= A.getCorner().getX()))||((A.getCorner().getX()<=B.getCorner().getX()+B.getHorizontal()) && (A.getCorner().getX()>=B.getCorner().getX()));
    
    //tells if the y-side of boxes ovelap
    bool y_overlap = ((B.getCorner().getY()<=A.getCorner().getY()+A.getVertical()) && (B.getCorner().getY()>= A.getCorner().getY()))||((A.getCorner().getY()<= B.getCorner().getY()+B.getVertical()) && (A.getCorner().getY()>=B.getCorner().getY()));
    
    return x_overlap && y_overlap;
}

Vector worldToView(Vector world_pos){
    Vector view_origin = WM.getView().getCorner();
    return world_pos - view_origin;
}

Vector viewToWorld(Vector view_pos){
    Vector view_origin = WM.getView().getCorner();
    return view_pos + view_origin;
}

using std::stringstream;

std::string toString(int i){
    std::stringstream ss;
    ss<<i;
    return ss.str();
}

}
