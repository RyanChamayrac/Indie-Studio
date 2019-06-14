/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Select.cpp
*/

#include "Select.hpp"

SelectPlayer::SelectPlayer(irr::IrrlichtDevice *windows)
{
    this->loadTextures(windows);
    //this->loadButtons(windows);
}

void SelectPlayer::loadTextures(irr::IrrlichtDevice *windows)
{
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("SelectBackground"),
            windows->getVideoDriver()->getTexture("./assets/images/indie.png")));
}

void SelectPlayer::run(irr::IrrlichtDevice *windows)
{
    windows->getVideoDriver()->draw2DImage(this->_textures["SelectBackground"], irr::core::position2d<irr::s32>(0,0),
            irr::core::rect<irr::s32>(0,0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}