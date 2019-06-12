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
    if (!this->getMap("assets/map/map.txt"))
        return;
    int starting_x = -20;
    int starting_y = 0;
    int x = 0;
    int y = 0;
    std::vector<irr::scene::IMeshSceneNode *> tmp;
/*
    irr::video::ITexture *rt = window->getVideoDriver()->
            addRenderTargetTexture(irr::core::dimension2d<irr::u32>(256,256), "RTT1");
*/

    for (auto &it : this->_map) {
        for (auto &it2 : it) {
            if (it2 == 'A') {
                tmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                   irr::core::vector3df((starting_x) + x * 2, (starting_y) + y * 2, 0.0f),
                   irr::core::vector3df(0.0f, 0.0f, 0.0f)));
/*
                tmp.back()->setMaterialTexture(0, rt);
*/
                tmp.back()->getMaterial(0).Shininess = 20.0f;
                tmp.back()->setMaterialFlag(irr::video::EMF_WIREFRAME, true);
/*
                window->getSceneManager()->getMeshManipulator()->setVertexColors(tmp.back()->getMesh(),
                        irr::video::SColor(255, 0,0,255));
*/
/*
                window->getSceneManager()->addLightSceneNode();
*/
            } else {
                tmp.push_back(nullptr);
            }
            x++;
        }
        std::cout << std::endl;
        x = 0;
        this->_cubes.push_back(tmp);
        y++;
    }
    window->getSceneManager()->addCameraSceneNode(nullptr, irr::core::vector3df(0, 0, -30),
          irr::core::vector3df(0, 10, 0));
}