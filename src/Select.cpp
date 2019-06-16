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
    this->selectTab = {
            {"blue", "cyan", "green", "orange", "red", "yellow", "purple"},
            {"blue", "cyan", "green", "orange", "red", "yellow", "purple"},
            {"blue", "cyan", "green", "orange", "red", "yellow", "purple"},
            {"blue", "cyan", "green", "orange", "red", "yellow", "purple"}
    };
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
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("retourMenu"),
            windows->getVideoDriver()->getTexture("./assets/buttons/back.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("selectPlay"),
            windows->getVideoDriver()->getTexture("./assets/buttons/play.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("blue"),
            windows->getVideoDriver()->getTexture("./assets/select/blue.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("cyan"),
            windows->getVideoDriver()->getTexture("./assets/select/cyan.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("green"),
            windows->getVideoDriver()->getTexture("./assets/select/green.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("orange"),
            windows->getVideoDriver()->getTexture("./assets/select/orange.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("red"),
            windows->getVideoDriver()->getTexture("./assets/select/red.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("yellow"),
            windows->getVideoDriver()->getTexture("./assets/select/yellow.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("purple"),
            windows->getVideoDriver()->getTexture("./assets/select/purple.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("ia"),
            windows->getVideoDriver()->getTexture("./assets/buttons/ia.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("ia_grey"),
            windows->getVideoDriver()->getTexture("./assets/buttons/ia2.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("p"),
            windows->getVideoDriver()->getTexture("./assets/buttons/p.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("p_grey"),
            windows->getVideoDriver()->getTexture("./assets/buttons/p2.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("x"),
            windows->getVideoDriver()->getTexture("./assets/buttons/x.png")));
}

void SelectPlayer::incSkin(int skin)
{
    if (this->nbSkin[skin] < 6)
        this->nbSkin[skin]++;
    else
        this->nbSkin[skin] = 0;
}

void SelectPlayer::changeRole(int role)
{
    if (this->nbRole[role][0] == 0) {
        this->nbRole[role][0] = 1;
        this->nbRole[role][1] = 0;
    } else {
        this->nbRole[role][0] = 0;
        this->nbRole[role][1] = 1;
    }
}

irr::video::ITexture *SelectPlayer::getSkin(int skin)
{
    return this->_textures[this->selectTab[skin][nbSkin[skin]]];
}

void SelectPlayer::run(irr::IrrlichtDevice *windows)
{
    windows->getVideoDriver()->draw2DImage(this->_textures["SelectBackground"], irr::core::position2d<irr::s32>(0,0),
            irr::core::rect<irr::s32>(0,0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    windows->getVideoDriver()->draw2DImage(this->getSkin(0), irr::core::position2d<irr::s32>(150, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    windows->getVideoDriver()->draw2DImage(this->getSkin(1), irr::core::position2d<irr::s32>(550, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    windows->getVideoDriver()->draw2DImage(this->getSkin(2), irr::core::position2d<irr::s32>(950, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    windows->getVideoDriver()->draw2DImage(this->getSkin(3), irr::core::position2d<irr::s32>(1350, 200),
            irr::core::rect<irr::s32>(0,0, 310, 400), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    this->_buttons["p1"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[0][0]]]);
    this->_buttons["ia1"]->setImage(this->_textures[this->selectRole[0][1][this->nbRole[0][1]]]);
    this->_buttons["p2"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[1][0]]]);
    this->_buttons["ia2"]->setImage(this->_textures[this->selectRole[0][1][this->nbRole[1][1]]]);
    this->_buttons["p3"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[2][0]]]);
    this->_buttons["ia3"]->setImage(this->_textures[this->selectRole[0][1][this->nbRole[2][1]]]);
    this->_buttons["ia4"]->setImage(this->_textures[this->selectRole[0][1][this->nbRole[3][1]]]);
    this->_buttons["p4"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[3][0]]]);
}

std::map<std::string, irr::gui::IGUIButton *> SelectPlayer::getButtons()
{
    return this->_buttons;
}

std::map<std::string, irr::video::ITexture *> SelectPlayer::getTextures()
{
    return this->_textures;
}

std::vector<std::vector<std::vector<std::string>>> SelectPlayer::getSelectRole()
{
    return this->selectRole;
}

std::vector<std::vector<int>> SelectPlayer::getNbRole()
{
    return this->nbRole;
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
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("retourMenu"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RETURN_SELECT_PLAY, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("selectPlay"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PLAY_SELECT, L"", L"Change player")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("ia1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_1, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("ia2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_2, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("ia3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_3, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("ia4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_4, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("p1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P1, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("p2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P2, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("p3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P3, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("p4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P4, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("x1"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_X1, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("x2"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_X2, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("x3"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_X3, L"", L"")));
    this->_buttons.insert(std::pair<std::string, irr::gui::IGUIButton *>(std::string("x4"),
            windows->getGUIEnvironment()->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_X4, L"", L"")));

    this->_buttons["changeSkin1"]->setImage(this->_textures["changeSkin1"]);
    this->_buttons["changeSkin2"]->setImage(this->_textures["changeSkin2"]);
    this->_buttons["changeSkin3"]->setImage(this->_textures["changeSkin3"]);
    this->_buttons["changeSkin4"]->setImage(this->_textures["changeSkin4"]);

    this->_buttons["p1"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[0][0]]]);
    this->_buttons["ia1"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[0][1]]]);
    this->_buttons["p2"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[1][0]]]);
    this->_buttons["ia2"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[1][1]]]);
    this->_buttons["ia3"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[2][1]]]);
    this->_buttons["p3"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[2][0]]]);
    this->_buttons["ia4"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[3][1]]]);
    this->_buttons["p4"]->setImage(this->_textures[this->selectRole[0][0][this->nbRole[3][0]]]);

    this->_buttons["x1"]->setImage(this->_textures["x"]);
    this->_buttons["x2"]->setImage(this->_textures["x"]);
    this->_buttons["x3"]->setImage(this->_textures["x"]);
    this->_buttons["x4"]->setImage(this->_textures["x"]);

    this->_buttons["retourMenu"]->setImage(this->_textures["retourMenu"]);
    this->_buttons["selectPlay"]->setImage(this->_textures["selectPlay"]);

    this->_buttons["changeSkin1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 650));
    this->_buttons["changeSkin2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 650));
    this->_buttons["changeSkin3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 650));
    this->_buttons["changeSkin4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 650));

    this->_buttons["p1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 750));
    this->_buttons["ia1"]->setRelativePosition(irr::core::position2d<irr::s32>(368, 750));
    this->_buttons["p2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 750));
    this->_buttons["ia2"]->setRelativePosition(irr::core::position2d<irr::s32>(768, 750));
    this->_buttons["p3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 750));
    this->_buttons["ia3"]->setRelativePosition(irr::core::position2d<irr::s32>(1168, 750));
    this->_buttons["p4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 750));
    this->_buttons["ia4"]->setRelativePosition(irr::core::position2d<irr::s32>(1568, 750));
    this->_buttons["x1"]->setRelativePosition(irr::core::position2d<irr::s32>(284, 750));
    this->_buttons["x2"]->setRelativePosition(irr::core::position2d<irr::s32>(684, 750));
    this->_buttons["x3"]->setRelativePosition(irr::core::position2d<irr::s32>(1084, 750));
    this->_buttons["x4"]->setRelativePosition(irr::core::position2d<irr::s32>(1484, 750));

    this->_buttons["retourMenu"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 925));
    this->_buttons["selectPlay"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 850));
}