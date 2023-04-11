#ifndef GAME_MAINSTATE_HPP
#define GAME_MAINSTATE_HPP

#include <libStorm.hpp>

#include "../nodes/MainState/all.hpp"

using namespace Storm;

class MainState : public State
{
public:
    void on_init() override;
    void on_destroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif
