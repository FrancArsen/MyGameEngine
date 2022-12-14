//
//  InputManager.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/8/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includes
#include "InputManager.h"
#include "DisplayManager.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "Manager.h"

namespace df{
InputManager::InputManager() {
    setType("InputManager");
}

void InputManager::operator=(InputManager const&) {
    
}

InputManager & InputManager::getInstance() {
    static InputManager im;
    return im;
}

int InputManager::startUp()
{
    //make sure dm is started
    if (DM.isStarted() == false)
    {
        return 0;
    }
    //disable key repeat
    DM.getWindow()->setKeyRepeatEnabled(false);
    
    //set started to true
    Manager::startUp();
    return 1;
}

void InputManager::shutDown() {
    //set key repeat true
    DM.getWindow()->setKeyRepeatEnabled(true);
    Manager::shutDown();
}

void InputManager::getInput()
{
    sf::Event event;
    while (DM.getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::MouseMoved)
        {
            EventMouse mouse = EventMouse();
            mouse.setMouseAction(MOVED);
            onEvent(&mouse);
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            EventMouse mouse = EventMouse();
            mouse.setMouseAction(PRESSED);
            onEvent(&mouse);
        }
    }
    if (sf::Keyboard::Up)
    {
        EventKeyboard kbd = EventKeyboard();
        kbd.setKey(Keyboard::UPARROW);
        onEvent(&kbd);
    }
    else if (sf::Keyboard::Down)
    {
        EventKeyboard kbd = EventKeyboard();
        kbd.setKey(Keyboard::DOWNARROW);
        onEvent(&kbd);
    }
    if (sf::Mouse::Left)
    {
        EventMouse mouse = EventMouse();
        mouse.setMouseButton(Mouse::LEFT);
        onEvent(&mouse);
    }
    else if (sf::Mouse::Right)
    {
        EventMouse mouse = EventMouse();
        mouse.setMouseButton(Mouse::RIGHT);
        onEvent(&mouse);
    }
}

}
