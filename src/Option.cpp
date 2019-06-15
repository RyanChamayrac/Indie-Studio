/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Option.cpp
*/

#include "Option.hpp"
#include "GameStat.hpp"

Option::Option(irr::IrrlichtDevice *window)
{
    this->loadTextures(window);
    this->loadButtons(window);
}

void Option::loadTextures(irr::IrrlichtDevice *window)
{
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("OptionBackground"),
            window->getVideoDriver()->getTexture("./assets/images/options.png")));
}

void Option::loadButtons(irr::IrrlichtDevice *window)
{

}

std::map<std::string, irr::gui::IGUIButton *> Option::getButtons()
{
    return this->_buttons;
}

void Option::run(irr::IrrlichtDevice *window)
{
    window->getVideoDriver()->draw2DImage(this->_textures["OptionBackground"], irr::core::position2d<irr::s32>(0,0),
            irr::core::rect<irr::s32>(0,0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}