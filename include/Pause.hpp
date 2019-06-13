/*
** EPITECH PROJECT, 2018
** OOP_indie_studio_2018
** File description:
** Pause.hpp
*/

#ifndef __PAUSE_HPP__
#define __PAUSE_HPP__

#include "GameStat.hpp"

class Pause : public GameStat {
    public:
        explicit Pause(irr::IrrlichtDevice *window);
        ~Pause() override = default;
        void loadTextures(irr::IrrlichtDevice *window) override;
        void loadButtons(irr::IrrlichtDevice *window) override;
        void run(irr::IrrlichtDevice *window) override;
        std::map<std::string, irr::gui::IGUIButton *> getButtons();

    private:
            std::map<std::string, irr::video::ITexture *> _textures;
            std::map<std::string, irr::gui::IGUIButton *> _buttons;
};

#endif