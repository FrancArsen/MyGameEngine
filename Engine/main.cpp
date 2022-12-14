//
//  main.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 1/29/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//system includes
#include <stdarg.h>
#include <time.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

//engine includes
#include "LogManager.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Clock.h"
#include "Vector.h"
#include "Object.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Event.h"
#include "EventStep.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "Saucer.h"
#include "Hero.h"
#include "Utility.h"
#include "ViewObject.h"
#include "EventView.h"




void tests();
void tests2();
void tests3();
void tests4();
void tests5();
void tests6();
void tests7();
void tests8();
void tests9();
void tests10();
void tests11();



int writeLog(const char *fmt, ...);

int main(){
    
    tests11();
}


int writeLog(const char *fmt, ...){
    //writing with arguements
    fprintf(stderr,"Message:");
    va_list args;
    va_start (args,fmt);
    vfprintf (stderr,fmt,args);
    va_end (args);
    fputs("\n",stderr);
}

void tests(){
    //testing writelog
    writeLog("");
    writeLog("testing,%f,%i",1.1,1);
    
    //testing writelog for LM
    LM.startUp();
    LM.writeLog("LogManger Tests:");
    int a = LM.writeLog("a");
    int b = LM.writeLog("");
    int c = LM.writeLog("testing,%f,%i",1.1,1);
    LM.writeLog("number of bytes for above examples: %i,%i,%i",a,b,c);
    
    //testing Clock
    LM.writeLog("\nClock Tests:");
    df::Clock clock;
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    sleep_time.tv_nsec = 20000000;
    LM.writeLog("%i",clock.delta());
    nanosleep(&sleep_time,NULL);
    LM.writeLog("%i",clock.split());
    LM.writeLog("%i",clock.delta());
    
    //testing Vector
    LM.writeLog("\nVector Tests:");
    LM.writeLog("\nGet X and Y");
    df::Vector vector1;
    LM.writeLog("%f %f",vector1.getX(),vector1.getY());
    df::Vector vector2 = df::Vector(3.0,4.0);
    LM.writeLog("%f %f",vector2.getX(),vector2.getY());
    LM.writeLog("\nSet X and Y");
    vector1.setX(2.0);
    vector1.setY(-2.5);
    vector2.setXY(4.0,3.0);
    LM.writeLog("%f %f",vector1.getX(),vector1.getY());
    LM.writeLog("%f %f",vector2.getX(),vector2.getY());
    LM.writeLog("\ngetMagnitude");
    LM.writeLog("%f %f",vector1.getMagnitude(),vector2.getMagnitude());
    LM.writeLog("\nscale");
    vector1.scale(-3.6);
    vector2.scale(2);
    LM.writeLog("%f %f",vector1.getX(),vector1.getY());
    LM.writeLog("%f %f",vector2.getX(),vector2.getY());
    LM.writeLog("\nnormalize");
    df::Vector vector3 = df::Vector(0.0,0.0);
    vector2.normalize();
    vector3.normalize();
    LM.writeLog("%f %f",vector3.getX(),vector3.getY());
    LM.writeLog("%f %f",vector2.getX(),vector2.getY());
    LM.writeLog("\noperator+");
    LM.writeLog("%f %f",vector2.operator+(vector1).getX(),vector2.operator+(vector1).getY());
    LM.writeLog("%f %f",vector1.operator+(vector1).getX(), vector1.operator+(vector1).getY());
    
    //testing object
    LM.writeLog("\nObject Tests:");
    df::Object object1;
    df::Object object2;
    df::Object object3;
    LM.writeLog("id: %i,%i,%i",object1.getId(),object2.getId(),object3.getId());
    
    
    //testing ObjectList
    LM.writeLog("\nObjectList Tests:");
    df::ObjectList obj_li1;
    
    LM.writeLog("testing isEmpty() \n%i", obj_li1.isEmpty());
    obj_li1.insert(&object1);
    obj_li1.insert(&object2);
    obj_li1.insert(&object3);
    LM.writeLog("%i \ntesting getCount() and insert() \n%i", obj_li1.isEmpty(),obj_li1.getCount());
    LM.writeLog("testing isFull() \n%i", obj_li1.isFull());
    obj_li1.remove(&object2);
    LM.writeLog("%i \ntesting remove() \n%i",obj_li1.isFull(),obj_li1.getCount());
    obj_li1.clear();
    LM.writeLog("testing clear() \n%i",obj_li1.getCount());
    
    //testing ObjectListIterator
    LM.writeLog("\nObjectListIterator Tests:");
    obj_li1.insert(&object1);
    obj_li1.insert(&object3);
    obj_li1.insert(&object2);
    df::ObjectListIterator obj_itr(&obj_li1);
    for (obj_itr.first(); !obj_itr.isDone(); obj_itr.next()) {
        LM.writeLog("%i",          obj_itr.currentObject()->getId());
    }
    
    //testing Event
    LM.writeLog("\nEvent Tests:");
    df::Event event;
    LM.writeLog("%s",event.getType().c_str());
    event.setType("df::step");
    LM.writeLog("%s",event.getType().c_str());
    
    //testing EventStep
    LM.writeLog("\nEventStep Tests:");
    df::EventStep stepevent;
    LM.writeLog("%s %i",stepevent.getType().c_str(),stepevent.getStepCount());
    stepevent.setType("df::default");
    stepevent.setStepCount(2);
    LM.writeLog("%s %i",stepevent.getType().c_str(),stepevent.getStepCount());
    
    df::EventStep stepevent2;
    df::Event event2;
    //testing eventHandler
    LM.writeLog("\nEventHandler Tests:");
    Saucer saucer;
    saucer.eventHandler(&stepevent2);
    saucer.eventHandler(&event2);
    
}

void tests2(){
    GM.startUp();
    
    //testing WorldManager
    LM.writeLog("\nWorldManager Tests:");
    Saucer* saucer1 = new Saucer;
    Saucer* saucer2 = new Saucer;
    Saucer* saucer3 = new Saucer;
    saucer3->setType("NotSaucer");
    LM.writeLog("%i %i",    WM.getAllObjects().getCount(),WM.objectsOfType("Saucer").getCount());
    WM.removeObject(saucer1);
    LM.writeLog("%i %i",    WM.getAllObjects().getCount(),WM.objectsOfType("Saucer").getCount());
    
    //testing mark for delete and update
    WM.markForDelete(saucer3);
    WM.update();
    LM.writeLog("%i %i",    WM.getAllObjects().getCount(),WM.objectsOfType("Saucer").getCount());

    //testing GameManager
    LM.writeLog("\nGameManager Tests:");
    GM.run();
}

void tests3(){
    GM.startUp();
    //testing onEvent
    LM.writeLog("\nOnEvent Tests:");
    Saucer saucer;
    df::EventStep *stepevent;
    LM.writeLog("%i",GM.onEvent(stepevent));
    GM.run();
}

void tests4(){
    // displaymanager tests
    GM.startUp();
    LM.writeLog("\nDisplayManager Tests:");
    Saucer saucer1;
    Saucer saucer2;
    Saucer saucer3;
    saucer1.setAltitude(4);
    saucer2.setAltitude(5);
    saucer3.setAltitude(-1);
    LM.writeLog("%i%i%i",saucer1.getAltitude(),saucer2.getAltitude(),saucer3.getAltitude());
    LM.writeLog("running starts");
    GM.run();
}

void tests5(){
    //input manager tests
    LM.startUp();
    LM.writeLog("\nInputManager Tests:");
    LM.writeLog("%i",IM.startUp());
    LM.writeLog("%i",DM.startUp());
    LM.writeLog("%i",IM.startUp());
    
    //eventmouse test
    LM.writeLog("\nEventMouse Tests:");
    df::EventMouse mouse;
    
    //eventkeyboard test
    LM.writeLog("\nEventKeyboard Tests:");

    df::EventKeyboard kbd;
}

void tests6(){
    //kenetics tests
    GM.startUp();
    LM.writeLog("\nKenetics Tests:");
    Saucer saucer1;
    Saucer saucer2;
    Saucer saucer3;
    Saucer saucer4;
    Hero hero;
    saucer1.setPosition(df::Vector(10,1));
    saucer2.setPosition(df::Vector(10,4));
    saucer3.setPosition(df::Vector(30,1));
    saucer4.setPosition(df::Vector(30,4));
    saucer3.setVelocity(df::Vector(-0.2,0));
    saucer4.setVelocity(df::Vector(-0.2,0));
    saucer4.setSolidness(df::SOFT);
    GM.run();
}

void tests7(){
    //collision tests
    GM.startUp();
    LM.writeLog("\nCollision Tests:");
    Saucer saucer1;
    Saucer saucer2;
    Saucer saucer3;
    Saucer saucer4;
    saucer1.setPosition(df::Vector(10,1));
    saucer2.setPosition(df::Vector(10,6));
    saucer3.setPosition(df::Vector(30,2));
    saucer4.setPosition(df::Vector(30,7));
    saucer3.setVelocity(df::Vector(-0.2,0));
    saucer4.setVelocity(df::Vector(-0.2,0));
    saucer4.setSolidness(df::SOFT);
    saucer1.setBox(df::Box(df::Vector(-0.5,-0.5),2,2));
    saucer2.setBox(df::Box(df::Vector(-0.5,-0.5),2,2));
    saucer3.setBox(df::Box(df::Vector(-0.5,-0.5),2,2));
    GM.run();
}
void tests8(){
    //view tests
    GM.startUp();
    LM.writeLog("\nview Tests:");
    Saucer saucer1;
    Saucer saucer2;
    Saucer saucer3;
    Saucer saucer4;

    saucer1.setPosition(df::Vector(30,35));
    saucer2.setPosition(df::Vector(60,35));
    saucer3.setPosition(df::Vector(60,40));
    saucer2.setVelocity(df::Vector(-0.2,0));
    saucer3.setVelocity(df::Vector(-0.2,0));
    saucer1.setBox(df::Box(df::Vector(-0.5,-0.5),2,2));
    saucer2.setBox(df::Box(df::Vector(-0.5,-0.5),2,2));
    WM.setBoundary(df::Box(df::Vector(0,0),120,70));
    WM.setView(df::Box(df::Vector(0,0),DM.getHorizontal(),DM.getVertical()));
    WM.setViewFollowing(&saucer2);
    GM.run();
}

void tests9(){
    //animation tests
    GM.startUp();
    LM.writeLog("\nAnimation Tests:");
    RM.loadSprite("sprites/good-spr.txt","Saucer");
    Saucer saucer1;
    saucer1.setPosition(df::Vector(10,10));
    GM.run();
}

void tests10(){
    //viewobject tests
    GM.startUp();
    LM.writeLog("\nViewObject Tests:");
    df::ViewObject vo1;
    df::ViewObject vo2;
    vo1.setViewString("points");
    vo2.setViewString("value");
    vo2.setColor(df::BLUE);
    vo2.setBorder(false);
    vo1.setLocation(df::TOP_LEFT);
    vo2.setLocation(df::TOP_CENTER);
    vo1.setValue(1);
    vo2.setValue(1);
    LM.writeLog("%f%f vo1",vo1.getPosition().getX(),vo1.getPosition().getY());
    LM.writeLog("%f%f vo2",vo2.getPosition().getX(),vo2.getPosition().getY());
    df::EventView ve1;
    df::EventView ve2;
    ve1.setValue(1);
    ve2.setValue(3);
    ve1.setTag("points");
    ve2.setTag("value");
    ve2.setDelta(false);
    WM.onEvent(&ve1);
    WM.onEvent(&ve2);
    GM.run();
}

void tests11(){
    //sounds tests
    GM.startUp();
    LM.writeLog("\nSounds Tests:");
    LM.writeLog("%d",RM.loadMusic("start-music.wav", "the"));
    LM.writeLog("%d",RM.loadSound("explode.wav", "Sound"));

    sf::Music music;
    music.openFromFile("start-music.wav");
    music.play();

    Saucer saucer1;
    saucer1.setPosition(df::Vector(10,10));
    GM.run();
}
