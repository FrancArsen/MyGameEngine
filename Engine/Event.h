//
//  Event.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/1/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef __EVENT_H__
#define __EVENT_H__

// sys includes.
#include <string>

namespace df {

const std::string UNDEFINED_EVENT = "df::undefined";

class Event {
    
private:
    std::string m_event_type;    // Event type (name).
    
public:
    // Create base event.
    Event();
    
    // Destructor.
    virtual ~Event();
    
    // Set event type.
    void setType(std::string new_type);  
    
    // Get event type.
    std::string getType() const;
}; 

}
#endif /* __EVENT_H__*/
