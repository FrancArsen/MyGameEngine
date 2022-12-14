//
//  EventKeyboard.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/9/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//

//engine includes
#include "EventKeyboard.h"

namespace df{

EventKeyboard::EventKeyboard()
{
    m_key_val = Keyboard::UNDEFINED_KEY;
    m_keyboard_action = UNDEFINED_KEYBOARD_ACTION;
    setType(KEYBOARD_EVENT);
}
void EventKeyboard::setKey(Keyboard::Key new_key)
{
    m_key_val = new_key;
}

Keyboard::Key EventKeyboard::getKey()const
{
    return m_key_val;
}

void EventKeyboard::setKeyboardAction(EventKeyboardAction new_action)
{
    m_keyboard_action = new_action;
}

EventKeyboardAction EventKeyboard::getKeyboardAction()const
{
    return m_keyboard_action;
}

}
