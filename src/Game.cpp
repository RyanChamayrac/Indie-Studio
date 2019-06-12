/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "Game.hpp"

void Game::run(irr::IrrlichtDevice *window)
{
    (void)window;
    if (this->_map.empty())
        return;
    for (auto &it : this->_cubes) {
        for (auto &it2 : it) {
            if (!it2)
                continue;
            it2->setVisible(false);
            window->getSceneManager()->drawAll();
            it2->setVisible(true);
        }
    }

}

void Game::loadTextures(irr::IrrlichtDevice *window)
{
    (void)window;
}

void Game::loadButtons(irr::IrrlichtDevice *window)
{
    (void)window;
}

int Game::generateMap()
{
    FILE* file = nullptr;
    int i = 0;
    int j = 0;
    int n = 0;

    file = fopen("map.txt", "w");
    if (!file)
        return -1;
    fputs("AAAAAAAAAAAAAAAAAAA\n", file);
    while (j < 17) {
        fputs("A", file);
        i = 0;
        while (i < 17) {
            n = rand();
            if ((i == 0 && j == 0) || (i == 0 && j == 16) || (i == 16 && j == 0) || (i == 16 && j == 16))
                fputs("x", file);
            else if ((i == 1 && j == 0) || (i == 0 && j == 1))
                fputs("x", file);
            else if ((i == 15 && j == 0) || (i == 16 && j == 1))
                fputs("x", file);
            else if ((i == 1 && j == 16) || (i == 0 && j == 15))
                fputs("x", file);
            else if ((i == 15 && j == 16) || (i == 16 && j == 15))
                fputs("x", file);
            else if (i % 2 != 0 && j % 2 != 0)
                fputs("A", file);
            else if (n % 2 == 0)
                fputs("T", file);
            else
                fputs("x", file);
            i++;
        }
        fputs("A\n", file);
        j++;
    }
    fputs("AAAAAAAAAAAAAAAAAAA", file);
    return 1;
}

bool Game::getMap(const std::string& fileName)
{
    std::ifstream in(fileName.c_str());
    std::string str;
    std::vector<char> tmp;

    if (!in) {
        std::cerr << "Loading map failed: "<<fileName<<std::endl;
        return false;
    }

    while (std::getline(in, str)) {
        if(str.empty())
            continue;
        for (auto it : str) {
            tmp.push_back(it);
        }
        this->_map.push_back(tmp);
        tmp.clear();
    }
    in.close();
    return true;
}

void Game::createBlocks(irr::IrrlichtDevice *window)
{
    int x = 0;
    int y = 0;
    std::vector<irr::scene::ISceneNode *> tmp;

    this->_bricks = window->getVideoDriver()->getTexture("./assets/blocks/RedBricks.bmp");
    this->_wooden = window->getVideoDriver()->getTexture("./assets/blocks/WoodenFloor.bmp");

    for (auto &it : this->_map) {
        for (auto &it2 : it) {
            if (it2 == 'A' || it2 == 'T') {
                tmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                      irr::core::vector3df(x * 2, - y * 2, 0.0f),
                      irr::core::vector3df(0.0f, 0.0f, 0.0f)));
                if (it2 == 'A')
                    tmp.back()->setMaterialTexture(0, this->_bricks);
                else
                    tmp.back()->setMaterialTexture(0, this->_wooden);
                tmp.back()->setMaterialFlag(irr::video::EMF_LIGHTING, true);
            } else {
                tmp.push_back(nullptr);
            }
            x++;
        }
        x = 0;
        this->_cubes.push_back(tmp);
        y++;
    }

}

Game::Game(irr::IrrlichtDevice *window) : _bricks(), _wooden()
{
    if (!this->getMap("assets/map/map.txt"))
        return;
    this->createBlocks(window);
    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(19, 0, -30),
                                                 irr::video::SColorf(1.0f, 1.0f, 1.0f));
    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(19, -38, -30),
                                                 irr::video::SColorf(1.0f, 1.0f, 1.0f));
    window->getSceneManager()->addCameraSceneNode(nullptr, irr::core::vector3df(19, -40, -38),
          irr::core::vector3df(19, -19, 0));
}