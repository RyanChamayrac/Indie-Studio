/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game.cpp
*/

#include "Game.hpp"

void Game::run(irr::IrrlichtDevice *window)
{
    int x = 0;
    if (this->_map.empty())
        return;
    window->getVideoDriver()->draw2DImage(this->_textures["gameBackground"], irr::core::position2d<irr::s32>(0, 0),
          irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
    for (auto &it : this->_players) {
        if (!it->getBombCube().second)
            continue;
        if ((float)(clock() - it->getTimer()) / CLOCKS_PER_SEC >= 1.00 && it->getBombCube().first)
            this->explosion(window, it);
        for (auto &it2 : this->_players) {
            if (!it2->getIsAlive() || !it2->getBombCube().second)
                continue;
            if (this->_map[static_cast<int>(- it2->getNode()->getPosition().Y / 2)]
                [static_cast<int>(it2->getNode()->getPosition().X / 2)] == 'e') {
                it->setIsAlive(false);
                it->getNode()->setVisible(false);
            }
            x++;
        }
        if ((float)(clock() - it->getTimer()) / CLOCKS_PER_SEC >= 1.50 && !it->getBombCube().first)
            this->endExplosion(it);
    }
}

void Game::loadTextures(irr::IrrlichtDevice *window)
{
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("RedBricks"),
          window->getVideoDriver()->getTexture("./assets/blocks/RedBricks.bmp")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("WoodenFloor"),
          window->getVideoDriver()->getTexture("./assets/blocks/WoodenFloor.bmp")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("gameBackground"),
          window->getVideoDriver()->getTexture("./assets/images/gameBackground.jpg")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("grass"),
          window->getVideoDriver()->getTexture("./assets/images/grass.jpg")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("explosion"),
          window->getVideoDriver()->getTexture("./assets/blocks/explosion.jpg")));
}

void Game::explosion(irr::IrrlichtDevice *window, Player *player)
{
    irr::scene::ISceneNode *bomb = player->getBombCube().second;
    int x_start = static_cast<int>(bomb->getPosition().X) / 2;
    int y_start = - static_cast<int>(bomb->getPosition().Y) / 2;

    for (int i = x_start - 1; i <= x_start + 1; i++) {
        if (i <= 0 || i >= 19 || this->_map[y_start][i] == 'A')
            continue;
        if (this->_cubes[y_start][i])
            this->_cubes[y_start][i]->remove();
        this->_map[y_start][i] = 'e';
        this->_cubes[y_start][i] = nullptr;
        this->_cubes[y_start][i] = window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
           irr::core::vector3df(i * 2, -y_start * 2, 0.0f),
           irr::core::vector3df(0.0f, 0.0f, 0.0f));
        this->_cubes[y_start][i]->setMaterialTexture(0, this->_textures["explosion"]);
        this->_cubes[y_start][i]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    }
    for (int i = y_start - 1; i <= y_start + 1; i++) {
        if (i <= 0 || i >= 19 || this->_map[i][x_start] == 'A')
            continue;
        if (this->_cubes[i][x_start])
            this->_cubes[i][x_start]->remove();
        this->_map[i][x_start] = 'e';
        this->_cubes[i][x_start] = nullptr;
        this->_cubes[i][x_start] = window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
           irr::core::vector3df(x_start * 2, -i * 2, 0.0f),
           irr::core::vector3df(0.0f, 0.0f, 0.0f));
        this->_cubes[i][x_start]->setMaterialTexture(0, this->_textures["explosion"]);
        this->_cubes[i][x_start]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    }
    player->setBombCube(std::pair<bool, irr::scene::ISceneNode *>(false, bomb));
}

void Game::endExplosion(Player *player)
{
    irr::scene::ISceneNode *bomb = player->getBombCube().second;
    int x_start = static_cast<int>(bomb->getPosition().X) / 2;
    int y_start = - static_cast<int>(bomb->getPosition().Y) / 2;

    for (int i = x_start - 1; i <= x_start + 1; i++) {
        if (i <= 0 || i >= 19 || this->_map[y_start][i] == 'A')
            continue;
        if (!this->_cubes[y_start][i])
            continue;
        this->_map[y_start][i] = 'x';
        this->_cubes[y_start][i]->remove();
        this->_cubes[y_start][i] = nullptr;
    }
    for (int i = y_start - 1; i <= y_start + 1; i++) {
        if (i <= 0 || i >= 19 || this->_map[i][x_start] == 'A')
            continue;
        if (!this->_cubes[i][x_start])
            continue;
        this->_map[i][x_start] = 'x';
        this->_cubes[i][x_start]->remove();
        this->_cubes[i][x_start] = nullptr;
    }
/*
    player->setBombCube(std::pair<bool, irr::scene::ISceneNode *>(true, bomb));
*/
    player->getBombCube().second->remove();
    player->setBombCube(std::pair<bool, irr::scene::ISceneNode *>(false, nullptr));
    player->setMap(this->_map);
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
        std::cerr << "Loading map failed: " << fileName << std::endl;
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

std::vector<std::vector<irr::scene::ISceneNode *>> Game::getCubes()
{
    return this->_cubes;
}

std::vector<std::vector<irr::scene::ISceneNode *>> Game::getFloor()
{
    return this->_floor;
}

std::vector<Player*> Game::getPlayers()
{
    return this->_players;
}

void Game::createBlocks(irr::IrrlichtDevice *window)
{
    int x = 0;
    int y = 0;
    std::vector<irr::scene::ISceneNode *> tmp;
    std::vector<irr::scene::ISceneNode *> floorTmp;

    this->loadTextures(window);
    for (auto &it : this->_map) {
        for (auto &it2 : it) {
            if (it2 == 'A' || it2 == 'T') {
                tmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                      irr::core::vector3df(x * 2, - y * 2, 0.0f),
                      irr::core::vector3df(0.0f, 0.0f, 0.0f)));
                if (it2 == 'A')
                    tmp.back()->setMaterialTexture(0, this->_textures["RedBricks"]);
                else
                    tmp.back()->setMaterialTexture(0, this->_textures["WoodenFloor"]);
                tmp.back()->setMaterialFlag(irr::video::EMF_LIGHTING, true);
            } else {
                tmp.push_back(nullptr);
            }

            floorTmp.push_back(window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
                  irr::core::vector3df(x * 2, - y * 2, 2.0f),
                  irr::core::vector3df(0.0f, 0.0f, 0.0f)));
            floorTmp.back()->setMaterialTexture(0, this->_textures["grass"]);
            floorTmp.back()->setMaterialFlag(irr::video::EMF_LIGHTING, true);

    x++;
    }
    x = 0;
    this->_cubes.push_back(tmp);
            this->_floor.push_back(floorTmp);
            tmp.clear();
            floorTmp.clear();
    y++;
    }
}

void Game::createPlayers(irr::IrrlichtDevice *window)
{
    for (int i = 0; i < 4; i++)
        this->_players.push_back(nullptr);
    this->_players[0] = new Player(window, irr::core::vector3df(2,-2,0), false, this->_cubes, this->_map);
    this->_players[1] = new Player(window, irr::core::vector3df(34,-34,0), true, this->_cubes, this->_map);
    this->_players[2] = new Player(window, irr::core::vector3df(2,-34,0), true, this->_cubes, this->_map);
    this->_players[3] = new Player(window, irr::core::vector3df(34,-2,0), true, this->_cubes, this->_map);
}

Game::Game(irr::IrrlichtDevice *window, bool _new) : _textures()
{
    if (_new) {
        std::cout << "make new" << std::endl;
        this->generateMap();
    }
    if (!this->getMap("assets/map/map.txt"))
        return;
    this->createBlocks(window);
    this->createPlayers(window);
    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(19, 0, -30),
                                                 irr::video::SColorf(1.0f, 1.0f, 1.0f));
    window->getSceneManager()->addLightSceneNode(nullptr, irr::core::vector3df(19, -38, -30),
                                                 irr::video::SColorf(1.0f, 1.0f, 1.0f));
    window->getSceneManager()->addCameraSceneNode(nullptr, irr::core::vector3df(19, -25, -38),
          irr::core::vector3df(19, -19, 0));
}