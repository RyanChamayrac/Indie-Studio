/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Player.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_PLAYER_HPP
#define OOP_INDIE_STUDIO_2018_PLAYER_HPP

#include <irrlicht.h>

class Player {

public:
    //CTOR
    Player(irr::IrrlichtDevice *window, const irr::core::vector3df&, bool IA);

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
    irr::scene::IAnimatedMesh *_mesh;
    direction_e _direction;
    irr::scene::IAnimatedMeshSceneNode * _node;
    irr::f32 _frameDeltaTime;
    bool _IA;
};


#endif //OOP_INDIE_STUDIO_2018_PLAYER_HPP
