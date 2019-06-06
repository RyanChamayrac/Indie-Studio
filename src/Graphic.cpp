/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Graphic.cpp
*/

#include "Graphic.hpp"

Graphic::Graphic()
{
    this->_window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080),
            16, false, false, false);

    if (!this->_window) {
        std::cerr << "Couldn't open a window" << std::endl;
        return;
    }
    this->_window->setWindowCaption(L"Indie Studio");
    this->_driver = this->_window->getVideoDriver();
    this->_smgr = this->_window->getSceneManager();
    this->_env = this->_window->getGUIEnvironment();
}

irr::IrrlichtDevice* Graphic::getWindow()
{
    return _window;
}

irr::video::IVideoDriver* Graphic::getDriver()
{
    return _driver;
}

irr::gui::IGUIEnvironment* Graphic::getEnv()
{
    return _env;
}

irr::scene::ISceneManager* Graphic::getsmgr()
{
    return _smgr;
}