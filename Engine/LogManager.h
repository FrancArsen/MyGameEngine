//
//  LogManager.h
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/29/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//
#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

// System includes.
#include <stdio.h>
#include <map>

// Engine includes.
#include "Manager.h"

// Two-letter acronym for easier access to manager.
#define LM df::LogManager::getInstance()

namespace df {

const std::string LOGFILE_DEFAULT = "dragonfly.log";

class LogManager : public Manager {
    
private:
    LogManager();                     // Private since a singleton.
    LogManager(LogManager const&);    // Don't allow copy.
    void operator=(LogManager const&);// Don't allow assignment.
    bool m_do_flush;                  // True if flush to disk after write.
    FILE *m_p_f;                      // Pointer to main logfile.
    bool m_fileisopen;                // tells if the file is open
    
public:
    // If logfile is open, close it.
    ~LogManager();
    
    // Get the one and only instance of the LogManager.
    static LogManager &getInstance();
    
    // Start up the LogManager (open main logfile "dragonfly.log").
    // return 0 if succeed, -1 if fail
    int startUp();
    
    // Shut down the LogManager (close logfile).
    void shutDown();
    
    // Set flush of logfile after each write.
    void setFlush(bool new_do_flush=true);
    
    // Write to logfile. Supports printf() formatting of strings.
    // Return number of bytes written (excluding prepends), -1 if error.
    int writeLog(const char *fmt, ...) const;
};

}
#endif /* __LOG_MANAGER_H__ */
