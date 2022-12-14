//
//  Vector.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/1/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//
#ifndef __DF_VECTOR_H__
#define __DF_VECTOR_H__

namespace df {

class Vector {
    
private:
    float m_x; 			//< Horizontal component.
    float m_y; 			//< Vertical component.
    
public:
    
    // Create Vector with (x,y).
    Vector(float init_x, float init_y);
    
    // Default is (0,0).
    Vector();
    
    void setX(float new_x);	        // Set horizontal component.
    float getX() const;		        // Get horizontal component.
    void setY(float new_y);	        // Set vertical component.
    float getY() const;		        // Get vertical component.
    void setXY(float new_x, float new_y); // Set horizizontal & vertical.
    void normalize();		        // Normalize vector.
    float getMagnitude() const;		// Return magnitude.
    void scale(float s);            // Scale vector.
    Vector operator+(const Vector &other) const; // Add Vector.
    Vector operator-(const Vector &other) const; // Subtract Vector.

    
};

} // end of namespace df
#endif /*__DF_VECTOR_H__*/
