//
//  Manager.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/29/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//


#ifndef __MANAGER_H__
#define __MANAGER_H__


// system includes.
#include <string>

// system includes.
#include "Event.h"

namespace df {

class Manager {
    
private:
    std::string m_type;		// Manager type identifier
    bool m_is_started;		// True if startUp() succeeded
    
protected:
    // Set type identifier of Manager.
    void setType(std::string new_type);
    
public:
    // Default constructor.
    Manager();
    
    // Default destructor.
    virtual ~Manager();
    
    // Get type identifier of Manager.
    std::string getType() const;
    
    // Startup Manager.
    // Return 0 if ok, else negative number.
    virtual int startUp();
    
    // Shutdown Manager.
    virtual void shutDown();
    
    // Return status of is_started (true when startUp() was successful).
    bool isStarted() const;
    
    int onEvent (const Event* p_event) const;
};

}
#endif /* __MANAGER_H__ */
