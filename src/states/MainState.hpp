#ifndef GAME_MAINSTATE_HPP
#define GAME_MAINSTATE_HPP

#include <libStorm.hpp>

#include "../nodes/MainState/all.hpp"

using namespace Storm;

class MainState : public State
{
public:
    void onInit() override;
    void onDestroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif
