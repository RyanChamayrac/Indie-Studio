/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "Game.hpp"

void Game::run(irr::IrrlichtDevice *window)
{
    window->getVideoDriver()->beginScene(true, true, irr::video::SColor(255,100,101,140));
    (void)window;
}

void Game::loadTextures(irr::IrrlichtDevice *window)
{
    (void)window;
}

void Game::loadButtons(irr::IrrlichtDevice *window)
{
    (void)window;
}

Game::Game(irr::IrrlichtDevice *window) {
    (void)window;
    std::cout << "game" << std::endl;
}