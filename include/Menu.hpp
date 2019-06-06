/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_MENU_HPP
#define OOP_INDIE_STUDIO_2018_MENU_HPP

#include "GameStat.hpp"
#include "Graphic.hpp"

class Menu : public GameStat {

public:
    explicit Menu(Graphic *graphic);
    ~Menu() = default;

    void run(Graphic *graphic) override;

    //Loaders
    void loadButtons(Graphic *graphic) override;
    void loadTextures(Graphic *graphic) override;



private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
};

#endif //OOP_INDIE_STUDIO_2018_MENU_HPP
