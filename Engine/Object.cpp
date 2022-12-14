//
//  Object.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/1/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includes
#include "Object.h"
#include "Vector.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "Animation.h"


namespace df{
Object::Object(){
    // object id increses everytime Object() is invoked
    static int id = 0;
    m_id = id;
    id++;
    
    //set type to default
    m_type = "Object";
    
    //set vector to 0,0
    Vector vector;
    m_position = vector;
    
    //setting altitude to half the maximum altitude
    m_altitude = MAX_ALTITUDE/2;
    
    //initialize position and speed
    m_direction = Vector(0,0);
    m_speed = 0;
    
    //initialize animation
    m_animation = Animation();
    
    //initializing the collision box
    setBox(m_animation.getBox());
    
    //putting it to WM
    WM.insertObject(this);
}
Object::~Object(){
    //removing it from WM
    WM.removeObject(this);
}


int Object::getId() const{
    return m_id;
}

void Object::setId(int new_id){
    m_id = new_id;
}

std::string Object::getType() const{
    return m_type;
}

void Object::setType(std::string new_type){
    m_type = new_type;
}

Vector Object::getPosition() const{
    return m_position;
}

void Object::setPosition(Vector new_position){
    m_position = new_position;
}

int Object::setAltitude(int new_altitude){
    //make sure altitude is acceptable
    if(new_altitude>MAX_ALTITUDE||new_altitude<0){
        return 0;
    }
    m_altitude = new_altitude;
    return 1;
}

int Object::getAltitude() const{
    return m_altitude;
}

int Object::eventHandler(const Event * p_e) {
    return 0;//does not consume any event
}

Vector Object::getDirection()const
{
    return m_direction;
}

void Object::setDirection(Vector new_direction)
{
    m_direction = new_direction;
}

float Object::getSpeed()const
{
    return m_speed;
}

void Object::setSpeed(float speed)
{
    m_speed = speed;
}

void Object::setVelocity(Vector new_velocity)
{
    m_speed = new_velocity.getMagnitude();
    new_velocity.normalize();
    m_direction = new_velocity;
}

Vector Object::getVelocity()const
{
    Vector velocity = m_direction;
    velocity.scale(m_speed);
    return velocity;
}

Vector Object::predictPosition()
{
    //Add Velocity to position
    Vector new_pos = getPosition()+getVelocity();

    return new_pos;
}

bool Object::isSolid()const
{
    if (m_solidness == HARD || SOFT)
    {
        return true;
    }
    return false;
}

int Object::setSolidness(Solidness new_solid)
{
    m_solidness = new_solid;
    return 0;
}

Solidness Object::getSolidness()const
{
    return m_solidness;
}

int Object::setSprite(std::string sprite_label){
    
    Sprite* p_sprite = RM.getSprite(sprite_label);
    if(p_sprite == NULL){
        return 0;
    }
    
    m_animation.setSprite(p_sprite);
}

void Object::setAnimation(Animation new_animation){
    m_animation = new_animation;
}

Animation Object::getAnimation() const{
    return m_animation;
}

int Object::draw(){
    Vector pos = getPosition();
    return m_animation.draw(pos);
}

void Object::setBox(Box new_box){
    m_box = new_box;
}

Box Object::getBox() const{
    return m_box;
}

Box Object::getWorldBox(Vector where) const{
    Box temp_box = getBox();
    Vector corner = temp_box.getCorner();
    temp_box.setCorner(corner + where);
    return temp_box;
}

}
