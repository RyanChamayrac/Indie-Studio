#include <utility>

/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player(irr::IrrlichtDevice *window, const irr::core::vector3df& position, bool IA,
               std::vector<std::vector<irr::scene::ISceneNode *>> cubes, std::vector<std::vector<char>> map)
{
    this->_bombTexture = window->getVideoDriver()->getTexture("./assets/blocks/tnt.jpg");
    this->_cubes = std::move(cubes);
    this->_map = std::move(map);
    this->_bombCube = nullptr;
    this->_direction = Player::DOWN;
    this->_window = window;
    this->_frameDeltaTime = 0.020;
    this->_IA = IA;
    this->_playerMesh = window->getSceneManager()->getMesh("assets/models/Bomberman.b3d");
    this->_playerNode = window->getSceneManager()->addAnimatedMeshSceneNode(this->_playerMesh);
    if (this->_playerNode) {
        this->_playerNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        this->_playerNode->setMaterialTexture(0, window->getVideoDriver()->getTexture("assets/models/Bomberman.png"));
        this->_playerNode->setRotation(irr::core::vector3df(-90, 0, 0));
    }
    this->_playerNode->setPosition(position);
}

irr::scene::IAnimatedMeshSceneNode * Player::getNode()
{
    return this->_playerNode;
}
bool Player::isIA()
{
    return this->_IA;
}

void Player::MoveRight()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    nodeRotation.Z = 90;
    nodePosition.X += this->_frameDeltaTime * 10.f;
    this->_playerNode->setFrameLoop(140, 160);
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
}

void Player::MoveLeft()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    nodeRotation.Z = 270;
    nodePosition.X -= this->_frameDeltaTime * 10.f;
    this->_playerNode->setFrameLoop(140, 160);
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
    this->_direction = Player::LEFT;
}

void Player::MoveUp()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    nodeRotation.Z = 180;
    nodePosition.Y += this->_frameDeltaTime * 10.f;
    this->_playerNode->setFrameLoop(140, 160);
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
    this->_direction = Player::UP;
}

void Player::MoveDown()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    nodeRotation.Z = 0;
    nodePosition.Y -= this->_frameDeltaTime * 10.f;
    this->_playerNode->setFrameLoop(140, 160);
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
    this->_direction = Player::DOWN;
}

int roundTo2(float nb)
{
    int r = static_cast<int>(round(nb));

    if (fmod(r, 2) == 0)
        return r;
    return r - 1;
}

void Player::action()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df intNodePosition;

    if (this->_bombCube)
        return;
    intNodePosition.X = roundTo2(nodePosition.X);
    intNodePosition.Y = roundTo2(nodePosition.Y);
    intNodePosition.Z = roundTo2(nodePosition.Z);
    this->_bombCube = this->_window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                                                intNodePosition,
                                                irr::core::vector3df(0.0f, 0.0f, 0.0f));
    this->_bombCube->setMaterialTexture(0, this->_bombTexture);
    this->_bombCube->setMaterialFlag(irr::video::EMF_LIGHTING, true);
}