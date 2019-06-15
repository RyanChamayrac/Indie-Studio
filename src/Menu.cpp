/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include "GameStat.hpp"

void Menu::loadTextures(irr::IrrlichtDevice *window)
{
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuBackground"),
            window->getVideoDriver()->getTexture("assets/images/background.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuExitButton"),
            window->getVideoDriver()->getTexture("assets/buttons/leave.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuNewButton"),
            window->getVideoDriver()->getTexture("assets/buttons/new.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuLoadButton"),
          window->getVideoDriver()->getTexture("assets/buttons/load.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuOptionsButton"),
            window->getVideoDriver()->getTexture("assets/buttons/options.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuNewpressed"),
            window->getVideoDriver()->getTexture("assets/buttons/new-pressed.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuLoadpressed"),
          window->getVideoDriver()->getTexture("assets/buttons/load-pressed.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuOptionspressed"),
        window->getVideoDriver()->getTexture("assets/buttons/options-pressed.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuLeavepressed"),
            window->getVideoDriver()->getTexture("assets/buttons/leave-pressed.png")));
}

void Menu::loadButtons(irr::IrrlichtDevice *window)
{
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuExit"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_QUIT_BUTTON, L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuNew"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_NEW_BUTTON, L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuLoad"),
             window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LOAD_BUTTON, L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuOptions"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTIONS_BUTTON, L"")));
    this->_buttons["menuExit"]->setImage(this->_textures["menuExitButton"]);
    this->_buttons["menuLoad"]->setImage(this->_textures["menuLoadButton"]);
    this->_buttons["menuNew"]->setImage(this->_textures["menuNewButton"]);
    this->_buttons["menuOptions"]->setImage(this->_textures["menuOptionsButton"]);
    this->_buttons["menuLoad"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 450));
    this->_buttons["menuNew"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 550));
    this->_buttons["menuOptions"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 500));
    this->_buttons["menuExit"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));
}

std::map<std::string, irr::gui::IGUIButton *> Menu::getButtons()
{
    return this->_buttons;
}

Menu::Menu(irr::IrrlichtDevice *window)
{
    this->loadTextures(window);
    this->loadButtons(window);
}

void Menu::run(irr::IrrlichtDevice *window)
{
    window->getVideoDriver()->draw2DImage(this->_textures["menuBackground"], irr::core::position2d<irr::s32>(0, 0),
            irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}