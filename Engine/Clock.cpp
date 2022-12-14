//
//  Clock.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/30/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

// sys include
#include <stdio.h>
#include <sys/time.h>

// engine include
#include "Clock.h"

namespace df{

Clock::Clock(){
    
    //getting system time
    timeval current_tv;
    gettimeofday (&current_tv , NULL);
    //turning system time to micro seconds
    long int current_msec = current_tv.tv_sec*1000000 + current_tv.tv_usec;
    m_previous_time = current_msec;// setting previous_time to current time
}

long int Clock::delta(){
    
    //return -1 if no previous time
    if (m_previous_time <= 0){
        return -1;}
    
    
    //get current time
    timeval current_tv;
    gettimeofday (&current_tv , NULL);
    
    //turning system time to micro seconds
    long int current_msec = current_tv.tv_sec*1000000 + current_tv.tv_usec;
    
    //record previous time
    long int temp_prev_time = m_previous_time;
    // setting previous_time to current time
    m_previous_time = current_msec;
    
    // counting time elapsed since last delta()
    long int time_elapsed = current_msec - temp_prev_time;
    
    return time_elapsed;
}

long int Clock::split() const{
    //return -1 if no previous time
    if (m_previous_time <= 0){
        return -1;}
        
    //get current time
    timeval current_tv;
    
    gettimeofday (&current_tv , NULL);
    //turning system time to micro seconds
    long int current_msec = current_tv.tv_sec*1000000 + current_tv.tv_usec;
    
    // counting time elapsed since last delta()
    long int time_elapsed = current_msec - m_previous_time;
    
    return time_elapsed;
}

}
