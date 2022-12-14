//
//  EventStep.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/2/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "EventStep.h"

namespace df{

EventStep::EventStep(){
    setType(STEP_EVENT);
    m_step_count = 0;
}

EventStep::EventStep(int init_step_count){
    setType(STEP_EVENT);
    m_step_count = init_step_count;
}

void EventStep::setStepCount(int new_step_count) {
    m_step_count = new_step_count;
}

int EventStep::getStepCount() const {
    return m_step_count;
}

}
