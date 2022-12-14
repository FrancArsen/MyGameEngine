//
//  EventMouse.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/9/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

#include "EventMouse.h"

namespace df{

EventMouse::EventMouse()
{
    setMouseAction(EventMouseAction::UNDEFINED_MOUSE_ACTION);
    setMouseButton(Mouse::Button::UNDEFINED_MOUSE_BUTTON);
    setType(MSE_EVENT);
}

void EventMouse::setMouseAction(EventMouseAction new_mouse_action)
{
    m_mouse_action = new_mouse_action;
}

EventMouseAction EventMouse::getMouseAction()const
{
    return m_mouse_action;
}

void EventMouse::setMouseButton(Mouse::Button new_mouse_button)
{
    m_mouse_button = new_mouse_button;
}

Mouse::Button EventMouse::getMouseButton()const
{
    return m_mouse_button;
}

void EventMouse::setMousePosition(Vector new_mouse_xy)
{
    m_mouse_xy = new_mouse_xy;
}

Vector EventMouse::getMousePosition()const
{
    return m_mouse_xy;
}

}
