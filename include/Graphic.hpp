/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Graphic.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_GRAPHIC_HPP
#define OOP_INDIE_STUDIO_2018_GRAPHIC_HPP

#include <irrlicht.h>
#include <iostream>

class Graphic
{

public:
    //CTOR
    Graphic();

    //DTOR
    ~Graphic() = default;
    irr::IrrlichtDevice *getWindow();
    irr::gui::IGUIEnvironment *getEnv();
    irr::video::IVideoDriver *getDriver();
    irr::scene::ISceneManager *getsmgr();

private:
    irr::IrrlichtDevice *_window;
    irr::gui::IGUIEnvironment *_env;
    irr::video::IVideoDriver *_driver;
    irr::scene::ISceneManager *_smgr;
};


#endif //OOP_INDIE_STUDIO_2018_GRAPHIC_HPP
