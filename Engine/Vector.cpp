//
//  Vector.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/31/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine include
#include "Vector.h"

// sys include
#include <math.h>

namespace df{

Vector::Vector(){
    m_x = 0;
    m_y = 0;
}

Vector::Vector(float init_x, float init_y){
    m_x = init_x;
    m_y = init_y;
}

void Vector::setX(float new_x){
    m_x = new_x;
}

float Vector::getX() const{
    return m_x;
}

void Vector::setY(float new_y){
    m_y = new_y;
}

float Vector::getY() const{
    return m_y;
}

void Vector::setXY(float new_x, float new_y){
    m_x = new_x;
    m_y = new_y;
}

float Vector::getMagnitude() const{
    float mag = sqrt(m_x*m_x + m_y*m_y);
    return mag;
}

void Vector::scale(float s){
    m_x = m_x*s;
    m_y = m_y*s;
}

void Vector::normalize(){
    float length = getMagnitude();
    if(length > 0){
        m_x = m_x/length;
        m_y = m_y/length;
    }
}
    
Vector Vector::operator+(const Vector &other) const{
    Vector v;
    v.m_x = m_x + other.m_x;
    v.m_y = m_y + other.m_y;
    return v;
}

Vector Vector::operator-(const Vector &other) const{
    Vector v;
    v.m_x = m_x - other.m_x;
    v.m_y = m_y - other.m_y;
    return v;
}
}