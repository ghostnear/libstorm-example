#ifndef GAME_MAINSTATE_HPP
#define GAME_MAINSTATE_HPP

#include <libstorm.hpp>
#include "../systems/systems.hpp"
#include "../components/components.hpp"

using namespace Storm;

class mainState : public State
{
public:
    void onInit() override;
    void onDestroy() override;
    void draw(GameManager* gm) override;
    void update(GameManager* gm, double dt) override;

private:
    World w;
    std::shared_ptr<RectDrawSystem> drawSystem;
};

#endif