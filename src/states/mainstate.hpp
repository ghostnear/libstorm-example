#ifndef GAME_MAINSTATE_HPP
#define GAME_MAINSTATE_HPP

#include <libstorm.hpp>

using namespace Storm;

class mainState : public State
{
    void onInit() override;
    void onDestroy() override;
    void draw(GameManager* gm) override;
    void update(GameManager* gm, double dt) override;
};

#endif