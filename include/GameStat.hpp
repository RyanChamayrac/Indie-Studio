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

#include "Graphic.hpp"

enum button{
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_PLAY_BUTTON = 102,
    GUI_ID_OPTIONS_BUTTON = 103,
};

class GameStat {

public:
    virtual void run(Graphic *graphic) = 0;

    //Loaders
    virtual void loadButtons(Graphic *graphic) = 0;
    virtual void loadTextures(Graphic *graphic) = 0;
};


#endif //OOP_INDIE_STUDIO_2018_GAMESTAT_HPP
