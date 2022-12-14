//
//  Clock.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/30/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#ifndef __Clock_h__
#define __Clock_h__

namespace df {

class Clock {
    
private:
    long int m_previous_time; //previous time delta() called (in microseconds)
    
public:
    //sets previous time to current time
    Clock();
    
    //return time elapsed since delta() was last called, -1 if error
    //resets previouss time
    //units are microsecond
    long int delta();
    
    //return time elapsed since delta() was last called, -1 if error
    //does not resets previouss time
    //units are microsecond
    long int split() const;
};
}
#endif /* __Clock_h__ */
