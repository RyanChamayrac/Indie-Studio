/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

void Menu::loadTextures(irr::IrrlichtDevice *window)
{
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuBackground"),
            window->getVideoDriver()->getTexture("./ressources/background.jpg")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuExitButton"),
            window->getVideoDriver()->getTexture("./ressources/EXIT.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuPlayButton"),
            window->getVideoDriver()->getTexture("./ressources/PLAY.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuHelpButton"),
            window->getVideoDriver()->getTexture("./ressources/HELP.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuOptionsButton"),
            window->getVideoDriver()->getTexture("./ressources/OPTIONS.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuTestButton"),
            window->getVideoDriver()->getTexture("./ressources/test.jpg")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuPlaypressed"),
            window->getVideoDriver()->getTexture("./assets/buttons/play-pressed.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("menuLeavepressed"),
            window->getVideoDriver()->getTexture("./assets/buttons/leave-pressed.png")));
}

void Menu::loadButtons(irr::IrrlichtDevice *window)
{
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuExit"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 425, 77), nullptr, GUI_ID_QUIT_BUTTON, L"Exit", L"Exits Program")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuPlay"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 425, 77), nullptr, GUI_ID_PLAY_BUTTON, L"Play", L"Play game")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("menuOptions"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 425, 77), nullptr, GUI_ID_OPTIONS_BUTTON, L"", L"Set options")));
    this->_buttons["menuExit"]->setImage(this->_textures["menuExitButton"]);
    this->_buttons["menuPlay"]->setImage(this->_textures["menuPlayButton"]);
    this->_buttons["menuOptions"]->setImage(this->_textures["menuOptionsButton"]);
    this->_buttons["menuExit"]->setRelativePosition(irr::core::position2d<irr::s32>(748, 800));
    this->_buttons["menuPlay"]->setRelativePosition(irr::core::position2d<irr::s32>(748, 200));
    this->_buttons["menuOptions"]->setRelativePosition(irr::core::position2d<irr::s32>(748, 500));
    this->_buttons["menuPlay"]->setPressedImage(this->_textures["menuPlaypressed"]);
    this->_buttons["menuExit"]->setPressedImage(this->_textures["menuLeavepressed"]);
}

void Menu::hideAll(irr::IrrlichtDevice *window)
{
    (void)window;
    for (auto & _button : this->_buttons) {
        std::cout << _button.first << std::endl;
        _button.second->setVisible(false);
        //_button.second->remove();
    }
}

Menu::~Menu()
{
    std::cout << "menu destroyed" << std::endl;
/*
    for (auto it = this->_textures.begin(); it != this->_textures.end(); ++it) {
        delete(it->second);
*/
/*
        it->second->drop();
*//*

    }
    for (auto it = this->_buttons.begin(); it != this->_buttons.end(); ++it) {
        delete(it->second);
*/
/*
        it->second->drop();
*//*

    }
*/
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