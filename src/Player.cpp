/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player(irr::IrrlichtDevice *window, const irr::core::vector3df& position, bool IA)
{
    this->_direction = Player::DOWN;
    this->_frameDeltaTime = 0.020;
    this->_IA = IA;
    this->_mesh = window->getSceneManager()->getMesh("assets/models/Bomberman.b3d");
    this->_node = window->getSceneManager()->addAnimatedMeshSceneNode(this->_mesh);
    if (this->_node) {
        this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        this->_node->setMaterialTexture(0, window->getVideoDriver()->getTexture("assets/models/Bomberman.png"));
        this->_node->setRotation(irr::core::vector3df(-90, 0, 0));
    }
    this->_node->setPosition(position);
}

irr::scene::IAnimatedMeshSceneNode * Player::getNode()
{
    return this->_node;
}
bool Player::isIA()
{
    return this->_IA;
}

void Player::MoveRight()
{
    irr::core::vector3df nodePosition = this->_node->getPosition();
    irr::core::vector3df nodeRotation = this->_node->getRotation();

    nodeRotation.Z = 90;
    nodePosition.X += this->_frameDeltaTime *10.f;
    this->_node->setFrameLoop(140, 160);
    this->_node->setRotation(nodeRotation);
    this->_node->setPosition(nodePosition);
}

void Player::MoveLeft()
{
    irr::core::vector3df nodePosition = this->_node->getPosition();
    irr::core::vector3df nodeRotation = this->_node->getRotation();

    nodeRotation.Z = 270;
    nodePosition.X -= this->_frameDeltaTime * 10.f;
    this->_node->setFrameLoop(140, 160);
    this->_node->setRotation(nodeRotation);
    this->_node->setPosition(nodePosition);
    this->_direction = Player::LEFT;
}

void Player::MoveUp()
{
    irr::core::vector3df nodePosition = this->_node->getPosition();
    irr::core::vector3df nodeRotation = this->_node->getRotation();

    nodeRotation.Z = 180;
    nodePosition.Y += this->_frameDeltaTime * 10.f;
    this->_node->setFrameLoop(140, 160);
    this->_node->setRotation(nodeRotation);
    this->_node->setPosition(nodePosition);
    this->_direction = Player::UP;
}

void Player::MoveDown()
{
    irr::core::vector3df nodePosition = this->_node->getPosition();
    irr::core::vector3df nodeRotation = this->_node->getRotation();

    nodeRotation.Z = 0;
    nodePosition.Y -= this->_frameDeltaTime * 10.f;
    this->_node->setFrameLoop(140, 160);
    this->_node->setRotation(nodeRotation);
    this->_node->setPosition(nodePosition);
    this->_direction = Player::DOWN;
}

void Player::action()
{
}