//
//  ObjectListIterator.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/1/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includes
#include "ObjectListIterator.h"
#include "Object.h"
#include "ObjectList.h"

namespace df{

ObjectListIterator::ObjectListIterator() {

}

ObjectListIterator::ObjectListIterator(const ObjectList * p_li) {
    //setting list to be iterated
    m_p_list = p_li;
    //get to the first item
    first();
}

void ObjectListIterator::first() {
    //getting to first item
    m_index = 0;
}

void ObjectListIterator::next() {
    //getting to nect item
    if (m_index < (m_p_list -> m_count)) {
        m_index++;
    }
}

bool ObjectListIterator::isDone() const {
    bool done = (m_index == (m_p_list -> m_count));
    return done;
}

Object* ObjectListIterator::currentObject() const {
    Object* curritem = m_p_list -> m_p_obj[m_index];
    return curritem;
}
}
