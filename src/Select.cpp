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
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changeSkin1"),
            windows->getVideoDriver()->getTexture("./assets/buttons/skin.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changeSkin2"),
            windows->getVideoDriver()->getTexture("./assets/buttons/skin.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changeSkin3"),
            windows->getVideoDriver()->getTexture("./assets/buttons/skin.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changeSkin4"),
            windows->getVideoDriver()->getTexture("./assets/buttons/skin.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changePlayer1"),
            windows->getVideoDriver()->getTexture("./assets/buttons/role.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changePlayer2"),
            windows->getVideoDriver()->getTexture("./assets/buttons/role.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changePlayer3"),
            windows->getVideoDriver()->getTexture("./assets/buttons/role.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("changePlayer4"),
            windows->getVideoDriver()->getTexture("./assets/buttons/role.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("retourMenu"),
            windows->getVideoDriver()->getTexture("./assets/buttons/back.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("selectPlay"),
            windows->getVideoDriver()->getTexture("./assets/buttons/play.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("blue"),
            windows->getVideoDriver()->getTexture("./assets/models/select/blue.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("cyan"),
            windows->getVideoDriver()->getTexture("./assets/models/select/cyan.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("green"),
            windows->getVideoDriver()->getTexture("./assets/models/select/green.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("orange"),
            windows->getVideoDriver()->getTexture("./assets/models/select/orange.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("red"),
            windows->getVideoDriver()->getTexture("./assets/models/select/red.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("yellow"),
            windows->getVideoDriver()->getTexture("./assets/models/select/blue.png")));
}

void SelectPlayer::run(irr::IrrlichtDevice *windows)
{
    windows->getVideoDriver()->draw2DImage(this->_textures["SelectBackground"], irr::core::position2d<irr::s32>(0,0),
            irr::core::rect<irr::s32>(0,0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
        windows->getVideoDriver()->draw2DImage(this->_textures["blue"], irr::core::position2d<irr::s32>(150, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    windows->getVideoDriver()->draw2DImage(this->_textures["green"], irr::core::position2d<irr::s32>(550, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    windows->getVideoDriver()->draw2DImage(this->_textures["red"], irr::core::position2d<irr::s32>(950, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    windows->getVideoDriver()->draw2DImage(this->_textures["yellow"], irr::core::position2d<irr::s32>(1350, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}

std::map<std::string, irr::gui::IGUIButton *> SelectPlayer::getButtons()
{
    return this->_buttons;
}

void SelectPlayer::loadButtons(irr::IrrlichtDevice *windows)
{
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeSkin1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_1, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeSkin2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_2, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeSkin3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_3, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changeSkin4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_4, L"", L"Change skin")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changePlayer1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_IA_1, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changePlayer2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_IA_2, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changePlayer3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_IA_3, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("changePlayer4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_IA_4, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("retourMenu"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RETURN_SELECT_PLAY, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("selectPlay"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PLAY_SELECT, L"", L"Change player")));

    this->_buttons["changeSkin1"]->setImage(this->_textures["changeSkin1"]);
    this->_buttons["changeSkin2"]->setImage(this->_textures["changeSkin2"]);
    this->_buttons["changeSkin3"]->setImage(this->_textures["changeSkin3"]);
    this->_buttons["changeSkin4"]->setImage(this->_textures["changeSkin4"]);

    this->_buttons["changePlayer1"]->setImage(this->_textures["changePlayer1"]);
    this->_buttons["changePlayer2"]->setImage(this->_textures["changePlayer2"]);
    this->_buttons["changePlayer3"]->setImage(this->_textures["changePlayer3"]);
    this->_buttons["changePlayer4"]->setImage(this->_textures["changePlayer4"]);

    this->_buttons["retourMenu"]->setImage(this->_textures["retourMenu"]);
    this->_buttons["selectPlay"]->setImage(this->_textures["selectPlay"]);

    this->_buttons["changeSkin1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 650));
    this->_buttons["changeSkin2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 650));
    this->_buttons["changeSkin3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 650));
    this->_buttons["changeSkin4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 650));

    this->_buttons["changePlayer1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 750));
    this->_buttons["changePlayer2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 750));
    this->_buttons["changePlayer3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 750));
    this->_buttons["changePlayer4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 750));

    this->_buttons["retourMenu"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 925));
    this->_buttons["selectPlay"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 850));
}