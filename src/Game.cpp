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

Game::Game(irr::IrrlichtDevice *window)
{
    (void)window;
    if (!this->getMap("assets/map/map.txt"))
        return;
    for (auto &it : this->_map) {
        for (auto &it2 : it)
            std::cout << it2;
    std::cout << std::endl;
    }
/*
    irr::scene::IMeshSceneNode* cube = window->getSceneManager()->addCubeSceneNode(2.0f, 0, -1,
       irr::core::vector3df(0.0f, 0.0f, 15.0f),
       irr::core::vector3df(0.0f, 0.0f, 0.0f));
    irr::scene::IMeshSceneNode* cube2 = window->getSceneManager()->addCubeSceneNode(2.0f, 0, -1,
        irr::core::vector3df(2.0f, 0.0f, 15.0f),
        irr::core::vector3df(0.0f, 0.0f, 0.0f));
    cube->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
    cube->setMaterialTexture(0, window->getVideoDriver()->getTexture("ressources/HELP.png"));
    cube2->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
    window->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0, 10, 0),
          irr::core::vector3df(0, -50, 100));
*/
}