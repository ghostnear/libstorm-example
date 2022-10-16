#ifndef GAME_MAINSTATE_HPP
#define GAME_MAINSTATE_HPP

#include <libstorm.hpp>
#include <prefabs/all.hpp>
#include "../nodes/mainState/all.hpp"

using namespace Storm;

class mainState : public State
{
public:
    void onInit() override;
    void onDestroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif
