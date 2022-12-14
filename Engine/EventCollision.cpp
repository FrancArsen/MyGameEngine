//
//  EventCollision.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/9/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Event.h"
#include "EventCollision.h"
#include "Object.h"

using namespace df;

EventCollision::EventCollision()
{
    setType(COLLISION_EVENT);
    m_pos = Vector();
    *m_p_obj1 = Object();
    *m_p_obj2 = Object();
}

EventCollision::EventCollision(Object* p_o1, Object* p_o2, Vector p)
{
    setType(COLLISION_EVENT);
    m_pos = p;
    m_p_obj1 = p_o1;
    m_p_obj2 = p_o2;
}

void EventCollision::setObject1(Object* p_new_o1)
{
    m_p_obj1 = p_new_o1;
}

Object* EventCollision::getObject1()const
{
    return m_p_obj1;
}

void EventCollision::setObject2(Object* p_new_o2)
{
    m_p_obj2 = p_new_o2;
}

Object* EventCollision::getObject2()const
{
    return m_p_obj2;
}

void EventCollision::setPosition(Vector new_pos)
{
    m_pos = new_pos;
}

Vector EventCollision::getPosition()const
{
    return m_pos;
}
