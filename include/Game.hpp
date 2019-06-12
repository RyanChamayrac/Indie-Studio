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
#include "GameStat.hpp"


class Game : public GameStat {

public:
    //CTOR
    explicit Game(irr::IrrlichtDevice *window);

    //DTOR
    ~Game() override = default;

    //Getters
    std::vector<std::vector<irr::scene::ISceneNode *>> getCubes();
    std::vector<std::vector<irr::scene::ISceneNode *>> getFloor();


    void run(irr::IrrlichtDevice *window) override;
    void loadButtons(irr::IrrlichtDevice *window) override;
    void loadTextures(irr::IrrlichtDevice *window) override;
    bool getMap(const std::string& fileName);
    void createBlocks(irr::IrrlichtDevice *window);
    int generateMap();

private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
    std::vector<std::vector<char>> _map;
    std::vector<std::vector<irr::scene::ISceneNode *>> _cubes;
    std::vector<std::vector<irr::scene::ISceneNode *>> _floor;
};


#endif //OOP_INDIE_STUDIO_2018_GAME_HPP
