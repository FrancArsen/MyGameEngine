//
//  Object.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/1/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef __OBJECT_H__
#define __OBJECT_H__

//sys includes.
#include <string>

//engine includes.
#include "Event.h"            // Objects can handle events.
#include "Vector.h"           // Objects need a float location.
#include "Sprite.h"
#include "Animation.h"
#include "Box.h"


namespace df {

// Types of solidness of Object.
enum Solidness {
  HARD,       // Object causes collisions and impedes.
  SOFT,       // Object causes collision, but doesn't impede.
  SPECTRAL,   // Object doesn't cause collisions.
};

class Object {
    
private:
    int m_id;		        // Unique game engine defined identifier.
    std::string m_type;	        // Game-programmer defined identification.
    Vector m_position;            // Position in game world.
    int m_altitude;            // altitude in the game world
    Vector m_direction;            // Direction vector.
    float m_speed;                // Object speed in direction.
    Solidness m_solidness;        // Solidness state of Object.
    Animation m_animation;        // Animation associated with Object.
    Box m_box;                   //the collision box of the object

public:
    
    // Construct Object.
    // Set default parameters and add to game world (WorldManager).
    Object();
    
    // Destroy object, removing itself from game world (WorldManager).
    virtual ~Object();
    
    // Set Object id.
    void setId(int new_id);
    
    // Get Object id.
    int getId() const;
    
    // Set type identifier of Object.
    void setType(std::string new_type);
    
    // Get type identifier of Object.
    std::string getType() const;
    
    // Set position of Object.
    virtual void setPosition(Vector new_position);
    
    // Get position of Object.
    Vector getPosition() const;
    
    //setting altitude of object, return 1 if ok
    int setAltitude(int new_altitude);
    
    //return altitude of object
    int getAltitude() const;
     
    // Set speed of Object.
    void setSpeed(float new_speed);

    // Get speed of Object.
    float getSpeed() const;

    // Set direction of Object.
    void setDirection(Vector new_direction);

    // Get direction of Object.
    Vector getDirection() const;

    // Set direction and speed of Object.
    void setVelocity(Vector new_velocity);

    // Get velocity of Object based on direction and speed.
    Vector getVelocity() const;

    // Predict Object position based on speed and direction.
    // Return predicted position.
    Vector predictPosition();
    
    // Return True if Object is HARD or SOFT, else false.
    bool isSolid() const;

    // Set solidness of Object, with checks for consistency.
    // Return 0 if ok, else -1.
    int setSolidness(Solidness new_solid);

    // Return solidness of Object.
    Solidness getSolidness() const;

    
    // Handles event, return 1 if consumed, 0 if not
    virtual int eventHandler(const Event * p_e);
    
    // Set Sprite for this Object to animate.
    // Return 0 if ok, else -1.
    int setSprite(std::string sprite_label);

    // Set Animation for this Object to new one.
    // Set bounding box to size of associated Sprite.
    void setAnimation(Animation new_animation);

    // Get Animation for this Object.
    Animation getAnimation() const;
    
    //draw object
    virtual int draw();
    
    // Set bounding box of Object.
    void setBox(Box new_box);

    // Get bounding box of Object.
    Box getBox() const;
    
    //get box with position of object    
    Box getWorldBox(Vector where) const;
};
}
#endif /* __OBJECT_H__*/
