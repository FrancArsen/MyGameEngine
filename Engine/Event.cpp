//
//  Event.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/2/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "Event.h"

namespace df {

Event::Event() {
}

Event::~Event() {
    
}

void Event::setType(std::string new_type) {
    m_event_type = new_type;
}

std::string Event::getType() const{
    return m_event_type;
}

}
