#ifndef GAME_SYSTEM_RECTDRAW_HPP
#define GAME_SYSTEM_RECTDRAW_HPP

#include <libstorm.hpp>
#include "../components/components.hpp"

using namespace Storm;

class RectDrawSystem : public System
{
public:
	void draw(World* w);
	void update(World* w, double dt);
};

#endif