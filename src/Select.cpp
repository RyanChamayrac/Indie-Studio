/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Select.cpp
*/

#include "Select.hpp"
#include "GameStat.hpp"

SelectPlayer::SelectPlayer(irr::IrrlichtDevice *windows)
{
    this->loadTextures(windows);
    this->loadButtons(windows);
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

std::map<std::string, irr::gui::IGUIButton *> SelectPlayer::getButtons()
{
    return this->_buttons;
}

void SelectPlayer::loadButtons(irr::IrrlichtDevice *windows)
{
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinleft1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_SKIN_1, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinright1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_SKIN_1, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinleft2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_SKIN_2, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinright2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_SKIN_2, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinleft3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_SKIN_3, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinright3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_SKIN_3, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinleft4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_SKIN_4, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeskinright4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_SKIN_4, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerleft1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_IA_1, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerright1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_IA_1, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerleft2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_IA_2, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerright2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_IA_2, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerleft3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_IA_3, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerright3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_IA_3, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerleft4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LEFT_IA_4, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeplayerright4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RIGHT_IA_4, L"", L"Change player")));
}