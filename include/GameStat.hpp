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
    GUI_ID_RETURN_MENU_BUTTON = 105
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
