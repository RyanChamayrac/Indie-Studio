/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Player.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_PLAYER_HPP
#define OOP_INDIE_STUDIO_2018_PLAYER_HPP

#include <irrlicht.h>
#include <vector>
#include <iostream>

class Player {

public:
    //CTOR
    Player(irr::IrrlichtDevice *window, const irr::core::vector3df&, bool IA,
            std::vector<std::vector<irr::scene::ISceneNode *>> cubes, std::vector<std::vector<char>> map);

    //DTOR
    ~Player() = default;

    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    void action();

    //Getters
    irr::scene::IAnimatedMeshSceneNode *getNode();
    bool isIA();


    enum direction_e {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

private:
    irr::scene::IAnimatedMesh *_playerMesh;
    irr::video::ITexture *_bombTexture;
    irr::scene::ISceneNode *_bombCube;
    direction_e _direction;
    irr::scene::IAnimatedMeshSceneNode * _playerNode;
    irr::f32 _frameDeltaTime;
    irr::IrrlichtDevice *_window;
    std::vector<std::vector<irr::scene::ISceneNode *>> _cubes;
    std::vector<std::vector<char>> _map;
    bool _IA;
};


#endif //OOP_INDIE_STUDIO_2018_PLAYER_HPP
