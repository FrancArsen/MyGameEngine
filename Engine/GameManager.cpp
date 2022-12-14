//
//  GameManager.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/30/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

// engine includes
#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Clock.h"
#include "EventStep.h"


namespace df{

GameManager::GameManager() {
    setType("GameManager");
}

GameManager::GameManager(GameManager const&){
    
}

void GameManager::operator=(GameManager const&){
    
}


GameManager& GameManager::getInstance() {
    static GameManager gm;
    return gm;
}

int GameManager::startUp() {
    Manager::startUp();
    
    // start other managers
    LM.startUp();
    WM.startUp();
    DM.startUp();
    IM.startUp();
    RM.startUp();
    
    //setting thhe view and boundary of game
    WM.setView(Box(Vector(),DM.getHorizontal(),DM.getVertical()));
    WM.setBoundary(Box(Vector(),DM.getHorizontal(),DM.getVertical()));
    
    //setting game over to be false
    m_game_over = false;
    return 0;
}

void GameManager::shutDown() {
    Manager::shutDown();
    
    // shut down other managers
    IM.shutDown();
    DM.shutDown();
    WM.shutDown();
    LM.shutDown();
    RM.shutDown();

    
    // set game over
    setGameOver();
}


void GameManager::setGameOver(bool new_game_over) {
    m_game_over = new_game_over;
}

bool GameManager::getGameOver() const {
    return m_game_over;
}

void GameManager::run(){
    Clock clock;
    Clock clock2;
    long int loop_time; // time of a loop
    int loop_count = 0;
    struct timespec sleep_time; // time to sleep
    sleep_time.tv_sec = 0;
    
    clock2.delta();
    //game loop
    while(!m_game_over){
        // start counting time
        clock.delta();
        
        //send each object step event
        EventStep stepevent;
        onEvent(&stepevent);
        
        //getting input from kbd and mouse
        IM.getInput();
        
        //updating in WM
        WM.update();
        
        //drawing all object
        WM.draw();
        
        //swap buffer
        DM.swapBuffers();
    
        
        //counting loop number, terminate if reachs 100
        loop_count ++;
        if(loop_count >= 200){
            GM.setGameOver();
        }
                
        //end counting time
        loop_time = clock.split();
        
        // sleep until frametime
        sleep_time.tv_nsec = (FRAME_TIME_DEFAULT*1000 - loop_time)*1000;
        nanosleep(&sleep_time,NULL);
    }
}

}
