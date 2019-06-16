/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Pause.cpp
*/

#include "Pause.hpp"

Pause::Pause(irr::IrrlichtDevice *window)
{
    this->loadTextures(window);
    this->loadButtons(window);
}

void Pause::loadTextures(irr::IrrlichtDevice *window)
{
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("pauseBackground"),
            window->getVideoDriver()->getTexture("./assets/images/pause.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("backMenu"),
            window->getVideoDriver()->getTexture("./assets/buttons/back.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("backMenupressed"),
            window->getVideoDriver()->getTexture("./assets/buttons/back-pressed.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("resumeGame"),
            window->getVideoDriver()->getTexture("./assets/buttons/resume.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("save"),
          window->getVideoDriver()->getTexture("./assets/buttons/save.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("resumeGamepressed"),
            window->getVideoDriver()->getTexture("./assets/buttons/resume-pressed.png")));
}

std::map<std::string, irr::gui::IGUIButton *> Pause::getButtons()
{
    return this->_buttons;
}

void Pause::loadButtons(irr::IrrlichtDevice *window)
{
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("backMenu"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RETURN_MENU_BUTTON, L"", L"Return to the menu")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("resumeGame"),
            window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RESUME_BUTTON, L"", L"Continue your game")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("save"),
             window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PAUSE_SAVE, L"", L"Save your game")));

    this->_buttons["backMenu"]->setImage(this->_textures["backMenu"]);
    this->_buttons["resumeGame"]->setImage(this->_textures["resumeGame"]);
    this->_buttons["save"]->setImage(this->_textures["save"]);
    this->_buttons["backMenu"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 500));
    this->_buttons["resumeGame"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 500));
    this->_buttons["save"]->setRelativePosition(irr::core::position2d<irr::s32>(850, 800));
}

void Pause::run(irr::IrrlichtDevice *window)
{
    window->getVideoDriver()->draw2DImage(this->_textures["pauseBackground"], irr::core::position2d<irr::s32>(0, 0),
            irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}