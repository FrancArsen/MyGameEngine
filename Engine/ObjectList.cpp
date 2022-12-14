//
//  ObjectList.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/1/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includess
#include "Object.h"
#include "ObjectList.h"

namespace df{

ObjectList::ObjectList(){
    m_count = 0;
}

void ObjectList::clear(){
    m_count = 0;
}

int ObjectList::insert(Object *p_o){
    //if reaches capacity, return -1
    if (m_count == MAX_OBJECTS){
        return -1;
    }

    //add to list
    m_p_obj[m_count] = p_o;
    m_count++;
    return 0;
}

int ObjectList::remove(Object *p_o){
    //finding corresponding object pointer
    for (int i=0; i<m_count ;i++){
        if(m_p_obj[i] == p_o){
            //switch spot on the list
            for(int j=i; j<m_count-1;j++){
                m_p_obj[j] = m_p_obj[j+1];
            }
            m_count --;
            return 1;
        }
    }
    return 0;
}

int ObjectList::getCount() const {
    return m_count;
}

bool ObjectList::isEmpty() const {
    if (m_count == 0) {
        return true;
    }
        return false;
}

bool ObjectList::isFull() const {
    if (m_count == MAX_OBJECTS) {
        return true;
    }
        return false;
}
}
