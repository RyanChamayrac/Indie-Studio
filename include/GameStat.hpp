/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** GameStat.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_GAMESTAT_HPP
#define OOP_INDIE_STUDIO_2018_GAMESTAT_HPP

#include <irrlicht.h>
#include <map>
#include <iostream>


enum button{
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_PLAY_BUTTON = 102,
    GUI_ID_OPTIONS_BUTTON = 103,
    GUI_ID_RESUME_BUTTON = 104,
    GUI_ID_RETURN_MENU_BUTTON = 105,
    GUI_ID_LEFT_SKIN_1 = 106,
    GUI_ID_RIGHT_SKIN_1 = 107,
    GUI_ID_LEFT_SKIN_2 = 108,
    GUI_ID_RIGHT_SKIN_2 = 109,
    GUI_ID_LEFT_SKIN_3 = 110,
    GUI_ID_RIGHT_SKIN_3 = 111,
    GUI_ID_LEFT_SKIN_4 = 112,
    GUI_ID_RIGHT_SKIN_4 = 113,
    GUI_ID_LEFT_IA_1 = 114,
    GUI_ID_RIGHT_IA_1 = 115,
    GUI_ID_LEFT_IA_2 = 116,
    GUI_ID_RIGHT_IA_2 = 117,
    GUI_ID_LEFT_IA_3 = 118,
    GUI_ID_RIGHT_IA_3 = 119,
    GUI_ID_LEFT_IA_4 = 120,
    GUI_ID_RIGHT_IA_4 = 121
};

class GameStat {

public:
    virtual ~GameStat() = default;
    virtual void run(irr::IrrlichtDevice *window) = 0;

    //Loaders
    virtual void loadButtons(irr::IrrlichtDevice *window) = 0;
    virtual void loadTextures(irr::IrrlichtDevice *window) = 0;
};


#endif //OOP_INDIE_STUDIO_2018_GAMESTAT_HPP
