/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Select.hpp
*/

#ifndef OOP_INDIE_STUDIO_2018_SELECT_HPP
#define OOP_INDIE_STUDIO_2018_SELECT_HPP

#include "Core.hpp"

class SelectPlayer {
public:
    explicit SelectPlayer(irr::IrrlichtDevice *windows);
    ~SelectPlayer() = default;
    void run(irr::IrrlichtDevice *windows);

    //Getter
    std::map<std::string, irr::gui::IGUIButton *> getButtons();
    std::map<std::string, irr::video::ITexture *> getTextures();
    std::vector<std::vector<std::vector<std::string>>> getSelectRole();
    std::vector<std::vector<int>> getNbRole(); 

    //Loader
    void loadButtons(irr::IrrlichtDevice *windows);
    void loadTextures(irr::IrrlichtDevice *windows);
    irr::video::ITexture *getSkin(int skin);
    irr::video::ITexture *getRole(int role);
    void incSkin(int skin);
    void changeRole(int role);

    void switchSkin(int pos);

private:
    std::map<std::string, irr::video::ITexture *> _textures;
    std::vector<int> _pos;
    std::vector<bool> _playersIA;
    std::map<std::string, irr::gui::IGUIButton *> _buttons;
    std::vector<std::vector<std::string>> selectTab;
    std::vector<std::vector<std::vector<std::string>>> selectRole= {
        {{"p", "p_grey"}, {"ia", "ia_grey"}}
    };
    int nbSkin[4] = {0, 1, 2, 3};
    std::vector<std::vector<int>> nbRole {
        {0, 1},
        {1, 0},
        {1, 0},
        {1, 0}
    };
};

#endif //OOP_INDIE_STUDIO_2018_SELECT_HPP