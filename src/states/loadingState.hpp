#ifndef GAME_LOADINGSTATE_HPP
#define GAME_LOADINGSTATE_HPP

#include <libstorm.hpp>
#include <prefabs/all.hpp>
#include "mainState.hpp"
#include "../nodes/all.hpp"

using namespace Storm;

class loadingState : public State
{
public:
    void onInit() override;
    void onDestroy() override;
    void draw() override;
    void update(double dt) override;
};

#endif