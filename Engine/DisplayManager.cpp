//
//  DisplayManager.cpp
//  IMGD3000 proj2a
//
//  Created by 方申 on 2/8/22.
//  Copyright © 2022 Shen Fang. All rights reserved.
//


// System includes
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

//engine includes
#include "DisplayManager.h"
#include "LogManager.h"
#include "Manager.h"
#include "Utility.h"


namespace df{

float charHeight(){
    return (DM.getVerticalPixels()/DM.getVertical());
}

float charWidth(){
    return (DM.getHorizontalPixels()/DM.getHorizontal());
}

Vector spacesToPixels(Vector spaces){
    //multiply with width and height
    spaces.setX(spaces.getX()*charWidth());
    spaces.setY(spaces.getY()*charHeight());
    return spaces;
}

Vector pixelsToSpaces(Vector pixels){
    //multiply with width and height
    pixels.setX(pixels.getX()/charWidth());
    pixels.setY(pixels.getY()/charHeight());
    return pixels;
}

DisplayManager::DisplayManager() {
    setType("DisplayManager");
    
    //initializing
    m_p_window = NULL;
    m_window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
    m_window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;
    m_window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT;
    m_window_vertical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;
    m_font = sf::Font();
}

void DisplayManager::operator=(DisplayManager const&) {
    
}

DisplayManager & DisplayManager::getInstance() {
    static DisplayManager dm;
    return dm;
}

int DisplayManager::startUp() {
    //checking if window already opened
    if (m_p_window != NULL){
        return 1;
    }
    
    //opening the window
    m_p_window = new sf::RenderWindow(sf::VideoMode(m_window_horizontal_pixels, m_window_vertical_pixels), WINDOW_TITLE_DEFAULT, WINDOW_STYLE_DEFAULT);
    
    //setting cursor invisible
    m_p_window->setMouseCursorVisible(false);
    
    //setting refresh rate same with monitor
    m_p_window->setVerticalSyncEnabled(true);
    
    //load font
    if (m_font.loadFromFile(FONT_FILE_DEFAULT) == false){
        LM.writeLog("f1, fail to load font");
        return 0;
    }
    
    //if all success, start up the manager
    if (m_p_window == NULL){
        LM.writeLog("f2，fail to load window");
        return 0;
    }
    
    //setting suatus startup
    Manager::startUp();
    return 1;
    
}

void DisplayManager::shutDown() {
    Manager::shutDown();
}

int DisplayManager::getHorizontal() const{
    return m_window_horizontal_chars;
}

int DisplayManager::getVertical() const{
    return m_window_vertical_chars;
}

int DisplayManager::getHorizontalPixels() const{
    return m_window_horizontal_pixels;
}

int DisplayManager::getVerticalPixels() const{
    return m_window_vertical_pixels;
}

sf::RenderWindow* DisplayManager::getWindow() const{
    return m_p_window;
}

int DisplayManager::drawCh(Vector world_pos, char ch, Color color) const{
    //make sure window is allcated
    if(m_p_window == NULL){
        return 0;
    }
    
    Vector view_pos = worldToView(world_pos);
    
    // convert spaces to pixels
    Vector pixel_pos = spacesToPixels(view_pos);
    
    
    //draw background rectangle since text is see through in SFML
    static sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(charWidth(),charHeight()));
    rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
    rectangle.setPosition(pixel_pos.getX() - charWidth()/10, pixel_pos.getY() + charHeight()/5);
    m_p_window->draw(rectangle);
    
    //create character to draw
    static sf::Text text("",m_font);
    text.setString(ch);
    text.setStyle(sf::Text::Bold);//make bold, since looks better
    
    //scale to right size
    if (charWidth() < charHeight()){
        text.setCharacterSize(charWidth()*2);
    }
    else text.setCharacterSize(charHeight()*2);
    
    
    //set SFML color based on Dragonfly color
    switch(color){
        case YELLOW:
            text.setFillColor(sf::Color::Yellow);
            break;
        case RED:
            text.setFillColor(sf::Color::Red);
            break;
        case GREEN:
            text.setFillColor(sf::Color::Green);
            break;
        case BLUE:
            text.setFillColor(sf::Color::Blue);
            break;
        case MAGENTA:
            text.setFillColor(sf::Color::Magenta);
            break;
        case CYAN:
            text.setFillColor(sf::Color::Cyan);
            break;
        case WHITE:
            text.setFillColor(sf::Color::White);
            break;
        case BLACK:
            text.setFillColor(sf::Color::Black);
            break;
        default:
            text.setFillColor(sf::Color::White);
            break;
    }
    
    //set position in window(in pixels)
    text.setPosition(pixel_pos.getX(), pixel_pos.getY());
    
    //draw character
    m_p_window->draw(text);
    
    return 1;
}

int DisplayManager::drawString(Vector pos, std::string str, Justification just, Color color) const{
    
    //setting justification
    Vector starting_pos = pos;
    switch(just){
        case CENTER_JUSTIFIED:
            starting_pos.setX(pos.getX() - str.size()/2);
            break;
        case RIGHT_JUSTIFIED:
            starting_pos.setX(pos.getX() - str.size());
            break;
        case LEFT_JUSTIFIED:
        default:
            break;
    }
    
    //drawing the string
    for(int i=0;i<str.size();i++){
        Vector temp_pos(starting_pos.getX()+i,starting_pos.getY());
        drawCh(temp_pos, str[i], color);
    }
    
    return 1;
}


int DisplayManager::swapBuffers(){
    //make sure window is allocated
    if(m_p_window == NULL){
        return 0;
    }
    
    //display curret window
    m_p_window->display();
    
    //clear other window to get ready for next draw
    m_p_window->clear();
    
    return 1;//success
}

}
