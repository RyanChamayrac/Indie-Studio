/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_MENU_HPP
#define OOP_INDIE_STUDIO_2018_MENU_HPP

#include "GameStat.hpp"

class Menu : public GameStat {

public:
    explicit Menu(irr::IrrlichtDevice *window);
    ~Menu() override = default;

    void run(irr::IrrlichtDevice *window) override;

    //Loaders
    void loadButtons(irr::IrrlichtDevice *window) override;
    void loadTextures(irr::IrrlichtDevice *window) override;



private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
};

#endif //OOP_INDIE_STUDIO_2018_MENU_HPP
