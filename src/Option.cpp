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
            window->getVideoDriver()->getTexture("assets/images/options.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("retour"),
            window->getVideoDriver()->getTexture("assets/buttons/back.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("mute"),
            window->getVideoDriver()->getTexture("assets/buttons/role.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("volume"),
            window->getVideoDriver()->getTexture("assets/buttons/role.png")));
}


void Option::run(irr::IrrlichtDevice *window)
{
    window->getVideoDriver()->draw2DImage(this->_textures["OptionBackground"], irr::core::position2d<irr::s32>(0,0),
            irr::core::rect<irr::s32>(0,0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}

std::map<std::string, irr::gui::IGUIButton *> Option::getButtons()
{
    return this->_buttons;
}

std::map<std::string, irr::gui::IGUIScrollBar *> Option::getScrollBars()
{
    return this->_scrollbars;
}

void Option::loadButtons(irr::IrrlichtDevice *window)
{
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("retour"),
        window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("mute"),
        window->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_MUTE, L"")));
    this->_scrollbars.insert(std::pair<std::string, irr::gui::IGUIScrollBar *>(std::string("volume"),
        window->getGUIEnvironment()->addScrollBar(true, irr::core::rect<irr::s32>(10,265,150,280), nullptr, GUI_ID_OPTION_3)));

    this->_buttons["retour"]->setImage(this->_textures["retour"]);
    this->_buttons["mute"]->setImage(this->_textures["mute"]);

    this->_buttons["retour"]->setRelativePosition(irr::core::position2d<irr::s32>(300, 500));
    this->_buttons["mute"]->setRelativePosition(irr::core::position2d<irr::s32>(1500, 500));
    this->_scrollbars["volume"]->setRelativePosition(irr::core::position2d<irr::s32>(900, 850));
}