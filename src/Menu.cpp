/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

void Menu::loadTextures(Graphic *graphic)
{
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuBackground"),
            graphic->getDriver()->getTexture("./ressources/background.jpg")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuExitButton"),
            graphic->getDriver()->getTexture("./ressources/EXIT.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuPlayButton"),
            graphic->getDriver()->getTexture("./ressources/PLAY.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuHelpButton"),
            graphic->getDriver()->getTexture("./ressources/HELP.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuOptionsButton"),
            graphic->getDriver()->getTexture("./ressources/OPTIONS.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuTestButton"),
            graphic->getDriver()->getTexture("./ressources/test.jpg")));
}

void Menu::loadButtons(Graphic *graphic)
{
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuExit"),
            graphic->getEnv()->addButton(irr::core::rect<irr::s32>(0, 0, 425, 77), nullptr, GUI_ID_QUIT_BUTTON, L"Exit", L"Exits Program")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuPlay"),
            graphic->getEnv()->addButton(irr::core::rect<irr::s32>(0, 0, 425, 77), nullptr, GUI_ID_PLAY_BUTTON, L"Play", L"Play game")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuOptions"),
            graphic->getEnv()->addButton(irr::core::rect<irr::s32>(0, 0, 425, 77), nullptr, GUI_ID_OPTIONS_BUTTON, L"", L"Set options")));
    this->_buttons["menuExit"]->setImage(this->_textures["menuExitButton"]);
    this->_buttons["menuPlay"]->setImage(this->_textures["menuPlayButton"]);
    this->_buttons["menuOptions"]->setImage(this->_textures["menuOptionsButton"]);
    this->_buttons["menuExit"]->setRelativePosition(irr::core::position2d<irr::s32>(748, 800));
    this->_buttons["menuPlay"]->setRelativePosition(irr::core::position2d<irr::s32>(748, 200));
    this->_buttons["menuOptions"]->setRelativePosition(irr::core::position2d<irr::s32>(748, 500));
}

Menu::Menu(Graphic *graphic)
{
    this->loadTextures(graphic);
    this->loadButtons(graphic);
}

void Menu::run(Graphic *graphic)
{
    graphic->getDriver()->draw2DImage(this->_textures["menuBackground"], irr::core::position2d<irr::s32>(0, 0),
            irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}