/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_GAME_HPP
#define OOP_INDIE_STUDIO_2018_GAME_HPP

#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <string>
#include <iostream>
#include <random>
#include "GameStat.hpp"
#include "Player.hpp"

class Game : public GameStat {

public:
    //CTOR
    explicit Game(irr::IrrlichtDevice *window, bool _new);

    //DTOR
    ~Game() override = default;

    //Getters
    std::vector<std::vector<irr::scene::ISceneNode *>> getCubes();
    std::vector<std::vector<irr::scene::ISceneNode *>> getFloor();
    std::vector<Player *> getPlayers();
    std::vector<irr::core::vector3df> getPlayersPositions();


    void run(irr::IrrlichtDevice *window) override;
    void loadButtons(irr::IrrlichtDevice *window) override;
    void loadTextures(irr::IrrlichtDevice *window) override;
    bool getMap(const std::string& fileName);
    void createBlocks(irr::IrrlichtDevice *window);
    void createPlayers(irr::IrrlichtDevice *window);
    void explosion(irr::IrrlichtDevice *window, Player *player);
    void endExplosion(irr::IrrlichtDevice *window, Player *player);
    irr::video::ITexture *randomBonus(char c);
    void addPlayerBonus(Player *player, int x, int y);
    int generateMap();
    std::vector<std::vector<char>> getTabMap();

private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
    std::vector<std::vector<char>> _map;
    std::vector<std::vector<irr::scene::ISceneNode *>> _cubes;
    std::vector<std::vector<irr::scene::ISceneNode *>> _floor;
    std::vector<Player *> _players;
};

#endif //OOP_INDIE_STUDIO_2018_GAME_HPP
