//
//  LogManager.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/29/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includes
#include "LogManager.h"

//system includes
#include <stdio.h>
#include <stdarg.h>

namespace df {

LogManager::LogManager() {
    setType("LogManager");
    
    // initializing
    m_p_f = NULL;
    m_do_flush = false;
    bool m_fileisopen = false;
}

LogManager::~LogManager(){
    if (m_fileisopen){
        fclose(m_p_f);
    }
}

LogManager::LogManager(LogManager const&){
    
}

void LogManager::operator=(LogManager const&){
    
}

LogManager& LogManager::getInstance() {
    static LogManager lm;
    return lm;
}

int LogManager::startUp(){
    Manager::startUp();
    
    //turning file name to const string
    const char *m_filenamecc = LOGFILE_DEFAULT.c_str();
    
    //open file
    m_p_f = fopen(m_filenamecc,"w");
    
    // return if file open succeed
    if (m_p_f == NULL){
        return -1;
    }
    else{
        return 0;
        m_fileisopen = true; //setting fileopen status to true
    }
}

void LogManager::shutDown(){
    Manager::shutDown();
    fclose(m_p_f); //closing file
    m_fileisopen = false; //setting fileopen status to false
}

int LogManager::writeLog(const char *fmt, ...) const{
    int byteswritten; //number of bytes written
    
    //writing with arguements
    va_list args;
    va_start (args,fmt);
    byteswritten = vfprintf (m_p_f,fmt,args);
    va_end (args);
    fputs("\n",m_p_f);
    
    //flush if set
    if(m_do_flush){
        fflush(m_p_f);
    }
    
    //returning the number of bytes written to file
    return byteswritten;
}

void LogManager::setFlush(bool new_do_flush){
    m_do_flush = true;
}
}
