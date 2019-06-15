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
    this->_bombCube = std::pair<bool, irr::scene::ISceneNode *>(false, nullptr);
    this->_bombTimer = 0;
    this->_direction = Player::DOWN;
    this->_window = window;
    this->_frameDeltaTime = 0.020;
    this->_IA = IA;
    this->_isAlive = true;
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

bool Player::getIsWalking()
{
    return this->_isWalking;
}

clock_t Player::getTimer()
{
    return this->_bombTimer;
}

std::pair<bool, irr::scene::ISceneNode *> Player::getBombCube()
{
    return this->_bombCube;
}

void Player::setIsWalking(bool res)
{
    this->_isWalking = res;
}

void Player::setBombCube(std::pair<bool, irr::scene::ISceneNode *> cube)
{
    this->_bombCube = cube;
}

void Player::setTimer()
{
    this->_bombTimer = clock();
}

bool Player::getIsAlive()
{
    return this->_isAlive;
}

void Player::setIsAlive(bool is)
{
    this->_isAlive = is;
}

void Player::setMap(std::vector<std::vector<char>> map)
{
    this->_map = std::move(map);
}

void Player::MoveRight()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    if (!this->_isAlive)
        return;
    nodeRotation.Z = 90;
    nodePosition.X += this->_frameDeltaTime * 10.f;
    if (this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X + this->_correction) / 2)] == 'A' ||
        this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X + this->_correction) / 2)] == 'T')
        return;
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
    this->_isWalking = true;
}

void Player::MoveLeft()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    if (!this->_isAlive)
        return;
    nodeRotation.Z = 270;
    nodePosition.X -= this->_frameDeltaTime * 10.f;
    if (this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] == 'A' ||
        this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] == 'T')
        return;
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
    this->_direction = Player::LEFT;
    this->_isWalking = true;
}

void Player::MoveUp()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    if (!this->_isAlive)
        return;
    nodeRotation.Z = 180;
    nodePosition.Y += this->_frameDeltaTime * 10.f;
    if (this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] == 'A' ||
        this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] == 'T')
        return;
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
    this->_direction = Player::UP;
    this->_isWalking = true;
}

void Player::MoveDown()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    if (!this->_isAlive)
        return;
    nodeRotation.Z = 0;
    nodePosition.Y -= this->_frameDeltaTime * 10.f;
    if (this->_map[static_cast<int>(-round(nodePosition.Y - this->_correction) / 2)][static_cast<int>(round(nodePosition.X) / 2)] == 'A' ||
        this->_map[static_cast<int>(-round(nodePosition.Y - this->_correction) / 2 )][static_cast<int>(round(nodePosition.X) / 2)] == 'T')
        return;
    this->_playerNode->setRotation(nodeRotation);
    this->_playerNode->setPosition(nodePosition);
    this->_direction = Player::DOWN;
    this->_isWalking = true;
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

    if (!this->_isAlive)
        return;
    if (this->_bombCube.second)
        return;
    intNodePosition.X = roundTo2(nodePosition.X);
    intNodePosition.Y = roundTo2(nodePosition.Y);
    intNodePosition.Z = roundTo2(nodePosition.Z);
    this->_bombCube.second = this->_window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                                                                                intNodePosition,
                                                                                irr::core::vector3df(0.0f, 0.0f, 0.0f));
    this->_bombCube.second->setMaterialTexture(0, this->_bombTexture);
    this->_bombCube.second->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    this->_bombCube.first = true;
    _bombTimer = clock();
}

void Player::Animate(int firstFrame, int lastFrame)
{
    this->_playerNode->setFrameLoop(firstFrame, lastFrame);
}

// Direction key map
/*if (this->_map[- static_cast<int>(nodePosition.Y)/2 - 1][static_cast<int>(nodePosition.X)/2] == 'x') {
    this->MoveUp();
} else if (this->_map[- static_cast<int>(nodePosition.Y)/2][static_cast<int>(nodePosition.X)/2 + 1] == 'x') {
    this->MoveRight();
} else if (this->_map[- static_cast<int>(nodePosition.Y)/2 + 1][static_cast<int>(nodePosition.X)/2] == 'x') {
    this->MoveDown();
} else if (this->_map[- static_cast<int>(nodePosition.Y)/2][static_cast<int>(nodePosition.X)/2 - 1] == 'x') {
    this->MoveLeft();
}*/

void Player::ia_move_left()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();
    int i = 1;

    while (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) - i] == 'x') {
        float tmp = nodePosition.X;
        while (nodePosition.X/2 >= (tmp/2 - 1)) {
            nodeRotation.Z = 270;
            nodePosition.X -= this->_frameDeltaTime * 1.f;
            if (!this->_isWalking)
                this->_playerNode->setFrameLoop(140, 160);
            if (this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] ==
                'A' ||
                this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] ==
                'T')
                return;
            this->_playerNode->setRotation(nodeRotation);
            this->_playerNode->setPosition(nodePosition);
            this->_direction = Player::LEFT;
            this->_isWalking = true;
            usleep(1000);
        }
        i++;
        if ((static_cast<int>(nodePosition.X/2) - i) < 0)
            return;
    }
}

void Player::ia_move_right()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();
    int i = 1;

    while (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) + i] == 'x') {
        float tmp = nodePosition.X;
        while (nodePosition.X/2 <= (tmp/2 + 1)) {
            nodeRotation.Z = 90;
            nodePosition.X += this->_frameDeltaTime * 1.f;
            if (!this->_isWalking)
                this->_playerNode->setFrameLoop(140, 160);
            if (this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(
                    round(nodePosition.X + this->_correction) / 2)] == 'A' ||
                this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(
                        round(nodePosition.X + this->_correction) / 2)] == 'T')
                return;
            this->_playerNode->setRotation(nodeRotation);
            this->_playerNode->setPosition(nodePosition);
            this->_direction = Player::RIGHT;
            this->_isWalking = true;
            usleep(1000);
        }
        i++;
        if ((static_cast<int>(nodePosition.X/2) + i) < 19)
            return;
    }
}

void Player::ia_move_up()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();
    int i = 1;

    while (this->_map[- static_cast<int>(nodePosition.Y/2) - i][static_cast<int>(nodePosition.X/2)] == 'x') {
        float tmp = nodePosition.Y;
        while (nodePosition.Y/2 <= (tmp/2 + 1)) {
            nodeRotation.Z = 180;
            nodePosition.Y += this->_frameDeltaTime * 1.f;
            if (!this->_isWalking)
                this->_playerNode->setFrameLoop(140, 160);
            if (this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] ==
                'A' ||
                this->_map[static_cast<int>(-round(nodePosition.Y) / 2)][static_cast<int>(round(nodePosition.X) / 2)] ==
                'T')
                return;
            this->_playerNode->setRotation(nodeRotation);
            this->_playerNode->setPosition(nodePosition);
            this->_direction = Player::UP;
            this->_isWalking = true;
            usleep(1000);
        }
        i++;
        if ((static_cast<int>(nodePosition.Y/2) - i) < 0)
            return;
    }
}

void Player::ia_move_down()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();
    int i = 1;

    while (this->_map[- static_cast<int>(nodePosition.Y/2) + i][static_cast<int>(nodePosition.X/2)] == 'x') {
        float tmp = nodePosition.Y;
        while (nodePosition.Y/2 >= (tmp/2 - 1)) {
            nodeRotation.Z = 0;
            nodePosition.Y -= this->_frameDeltaTime * 1.f;
            if (!this->_isWalking)
                this->_playerNode->setFrameLoop(140, 160);
            if (this->_map[static_cast<int>(-round(nodePosition.Y - this->_correction) / 2)][static_cast<int>(
                    round(nodePosition.X) / 2)] == 'A' ||
                this->_map[static_cast<int>(-round(nodePosition.Y - this->_correction) / 2 )][static_cast<int>(
                        round(nodePosition.X) / 2)] == 'T')
                return;
            this->_playerNode->setRotation(nodeRotation);
            this->_playerNode->setPosition(nodePosition);
            this->_direction = Player::DOWN;
            this->_isWalking = true;
            usleep(1000);
        }
        i++;
        if ((- static_cast<int>(nodePosition.Y/2) + i) == 19)
            return;
    }
}

void Player::ia_start()
{
    int a = rand() % 5;
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();

    if (a == 0) {
        if (this->_map[- static_cast<int>(nodePosition.Y/2) - 1][static_cast<int>(nodePosition.X/2)] == 'x') {
            ia_move_up();
            nodePosition = this->_playerNode->getPosition();
            nodeRotation = this->_playerNode->getRotation();
            if ((this->_map[- static_cast<int>(nodePosition.Y/2) + 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2) - 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) + 1] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) - 1] == 'T')) {
                this->action();
            }
        }
    } else if (a == 1) {
        if (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) + 1] == 'x') {
            ia_move_right();
            nodePosition = this->_playerNode->getPosition();
            nodeRotation = this->_playerNode->getRotation();
            if ((this->_map[- static_cast<int>(nodePosition.Y/2) + 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2) - 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) + 1] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) - 1] == 'T')) {
                this->action();
            }
        }
    } else if (a == 2) {
        if (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) - 1] == 'x') {
            ia_move_left();
            nodePosition = this->_playerNode->getPosition();
            nodeRotation = this->_playerNode->getRotation();
            if ((this->_map[- static_cast<int>(nodePosition.Y/2) + 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2) - 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) + 1] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) - 1] == 'T')) {
                this->action();
            }
        }
    } else if (a == 3) {
        if (this->_map[- static_cast<int>(nodePosition.Y/2) + 1][static_cast<int>(nodePosition.X/2)] == 'x') {
            ia_move_down();
            nodePosition = this->_playerNode->getPosition();
            nodeRotation = this->_playerNode->getRotation();
            if ((this->_map[- static_cast<int>(nodePosition.Y/2) + 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2) - 1][static_cast<int>(nodePosition.X/2)] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) + 1] == 'T')
                || (this->_map[- static_cast<int>(nodePosition.Y/2)][static_cast<int>(nodePosition.X/2) - 1] == 'T')) {
                this->action();
            }
        }
    }
}

void Player::ia_careful()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();


}


void Player::ia_rand_direction()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();


}


void Player::ia_put_bomb()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();


}

void Player::ia_to_bonus()
{
    irr::core::vector3df nodePosition = this->_playerNode->getPosition();
    irr::core::vector3df nodeRotation = this->_playerNode->getRotation();


}

void Player::ia_core()
{
    ia_start();
}
