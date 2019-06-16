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
        this->addPlayerBonus(it, static_cast<int>(- it->getNode()->getPosition().Y / 2),
                             static_cast<int>(it->getNode()->getPosition().X / 2));
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
            this->endExplosion(window, it);
    }
    int a = rand() % 3;
    if (a == 0)
        this->_players[2]->ia_core();
    else if (a == 2)
        this->_players[3]->ia_core();
}

void Game::addPlayerBonus(Player *player, int y, int x)
{
    switch (this->_map[y][x]) {
        case '0':
            player->setBonuses("BombUp");
            if (this->_cubes[y][x])
                this->_cubes[y][x]->remove();
            this->_cubes[y][x] = nullptr;
            break;
        case '1':
            player->setBonuses("SpeedUp");
            if (this->_cubes[y][x])
                this->_cubes[y][x]->remove();
            this->_cubes[y][x] = nullptr;
            break;
        case '2':
            player->setBonuses("FireUp");
            if (this->_cubes[y][x])
                this->_cubes[y][x]->remove();
            this->_cubes[y][x] = nullptr;
            break;
        case '3':
            player->setBonuses("WallPass");
            if (this->_cubes[y][x])
                this->_cubes[y][x]->remove();
            this->_cubes[y][x] = nullptr;
            break;
        default:
            break;
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
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("BombUp"),
          window->getVideoDriver()->getTexture("./assets/blocks/BombUp.jpg")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("SpeedUp"),
          window->getVideoDriver()->getTexture("./assets/blocks/SpeedUp.png")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("FireUp"),
          window->getVideoDriver()->getTexture("./assets/blocks/FireUp.jpg")));
    this->_textures.insert(std::pair<std::string, irr::video::ITexture *>(std::string("WallPass"),
          window->getVideoDriver()->getTexture("./assets/blocks/WallPass.png")));
}

irr::video::ITexture *Game::randomBonus(char c)
{
    switch(c) {
        case '0':
            return this->_textures["BombUp"];
        case '1':
            return this->_textures["SpeedUp"];
        case '2':
            return this->_textures["FireUp"];
        case '3':
            return this->_textures["WallPass"];
        default:
            break;
    }
    return nullptr;
}

void Game::explosion(irr::IrrlichtDevice *window, Player *player)
{
    irr::scene::ISceneNode *bomb = player->getBombCube().second;
    int x_start = static_cast<int>(bomb->getPosition().X) / 2;
    int y_start = - static_cast<int>(bomb->getPosition().Y) / 2;
    char res = 0;
    int size = 0;

    if (player->getBonuses()["FireUp"])
        size = 2;
    else
        size = 1;
    for (int i = x_start - size; i <= x_start + size; i++) {
        if (i <= 0 || i >= 19 || this->_map[y_start][i] == 'A')
            continue;
        if (this->_cubes[y_start][i])
            this->_cubes[y_start][i]->remove();
        if (this->_map[y_start][i] == 'T') {
            res = '0' + (rand() % 10);
            if (res < '5')
                this->_map[y_start][i] = 'i';
        } else
            this->_map[y_start][i] = 'e';
        this->_cubes[y_start][i] = nullptr;
        this->_cubes[y_start][i] = window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
           irr::core::vector3df(i * 2, -y_start * 2, 0.0f),
           irr::core::vector3df(0.0f, 0.0f, 0.0f));
        this->_cubes[y_start][i]->setMaterialTexture(0, this->_textures["explosion"]);
        this->_cubes[y_start][i]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
    }
    for (int i = y_start - size; i <= y_start + size; i++) {
        if (i <= 0 || i >= 19 || i == y_start || this->_map[i][x_start] == 'A')
            continue;
        if (this->_cubes[i][x_start])
            this->_cubes[i][x_start]->remove();
        if (this->_map[i][x_start] == 'T') {
            res = '0' + (rand() % 10);
            if (res < 5)
                this->_map[i][x_start] = 'i';
        } else
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

void Game::endExplosion(irr::IrrlichtDevice *window, Player *player)
{
    irr::scene::ISceneNode *bomb = player->getBombCube().second;
    int x_start = static_cast<int>(bomb->getPosition().X) / 2;
    int y_start = - static_cast<int>(bomb->getPosition().Y) / 2;
    char c = 0;
    int size = 0;

    if (player->getBonuses()["FireUp"])
        size = 2;
    else
        size = 1;
    for (int i = x_start - size; i <= x_start + size; i++) {
        if (i <= 0 || i >= 19 || this->_map[y_start][i] == 'A')
            continue;
        if (!this->_cubes[y_start][i])
            continue;
        this->_cubes[y_start][i]->remove();
        this->_cubes[y_start][i] = nullptr;
        if (this->_map[y_start][i] == 'i') {
            this->_cubes[y_start][i] = window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
               irr::core::vector3df(i * 2, -y_start * 2, 0.0f),
               irr::core::vector3df(0.0f, 0.0f, 0.0f));
            c = '0' + rand() % 4;
            this->_cubes[y_start][i]->setMaterialTexture(0, this->randomBonus(c));
            this->_cubes[y_start][i]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
            this->_map[y_start][i] = c;
        } else
            this->_map[y_start][i] = 'x';
    }
    for (int i = y_start - size; i <= y_start + size; i++) {
        if (i <= 0 || i >= 19 || i == y_start || this->_map[i][x_start] == 'A')
            continue;
        if (!this->_cubes[i][x_start])
            continue;
        this->_cubes[i][x_start]->remove();
        this->_cubes[i][x_start] = nullptr;
        if (this->_map[i][x_start] == 'i') {
            this->_cubes[i][x_start] = window->getSceneManager()->addCubeSceneNode(2.0f, nullptr, -1,
               irr::core::vector3df(x_start * 2, -i * 2, 0.0f),
               irr::core::vector3df(0.0f, 0.0f, 0.0f));
            c = '0' + rand() % 4;
            this->_cubes[i][x_start]->setMaterialTexture(0, this->randomBonus(c));
            this->_cubes[i][x_start]->setMaterialFlag(irr::video::EMF_LIGHTING, true);
            this->_map[i][x_start] = c;
        } else
            this->_map[i][x_start] = 'x';
    }
    player->getBombCube().second->remove();
    player->setBombCube(std::pair<bool, irr::scene::ISceneNode *>(false, nullptr));
    player->setMap(this->_map);
}

void Game::loadButtons(irr::IrrlichtDevice *window)
{
    (void)window;
}

std::vector<irr::core::vector3df> Game::getPlayersPositions()
{
    std::vector<irr::core::vector3df> ret;

    for (auto &it : this->_players)
        ret.push_back(it->getNode()->getPosition());
    return ret;
}

int Game::generateMap()
{
    int i = 0;
    int j = 0;
    int n = 0;
    std::ofstream file;
    file.open ("assets/map/map.txt");

    if (!file)
        return -1;
    file << "AAAAAAAAAAAAAAAAAAA\n";
    while (j < 17) {
        file << "A";
        i = 0;
        while (i < 17) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(1, 11600);
            n = dis(gen);
            if (i == 0 && j == 0)
                file << ",";
            else if (i == 0 && j == 16)
                file << ":";
            else if (i == 16 && j == 0)
                file << ";";
            else if (i == 16 && j == 16)
                file << "!";
            else if ((i == 1 && j == 0) || (i == 0 && j == 1))
                file << "x";
            else if ((i == 15 && j == 0) || (i == 16 && j == 1))
                file << "x";
            else if ((i == 1 && j == 16) || (i == 0 && j == 15))
                file << "x";
            else if ((i == 15 && j == 16) || (i == 16 && j == 15))
                file << "x";
            else if (i % 2 != 0 && j % 2 != 0)
                file << "A";
            else if (n % 2 == 0)
                file << "T";
            else
                file << "x";
            i++;
        }
        file << "A\n";
        j++;
    }
    file << "AAAAAAAAAAAAAAAAAAA";
    file.close();
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

std::vector<std::vector<char>> Game::getTabMap()
{
    return this->_map;
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
    this->_players[0] = new Player(window, ',', false, this->_cubes, this->_map);
    this->_players[1] = new Player(window, ';', true, this->_cubes, this->_map);
    this->_players[2] = new Player(window, ':', true, this->_cubes, this->_map);
    this->_players[3] = new Player(window, '!', true, this->_cubes, this->_map);
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
