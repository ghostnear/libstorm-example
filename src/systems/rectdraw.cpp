#include "rectdraw.hpp"

void RectDrawSystem::draw(World* w)
{
	for (auto const& entity : _entities)
	{
        auto& rect = w -> getComponent<FRect>(entity);
        
        SDL_SetRenderDrawColor(Graphics::getSDL(), 50, 130, 155, 255);
        SDL_Rect r;
        r.x = rect.pos.x;
        r.y = rect.pos.y;
        r.w = rect.size.x;
        r.h = rect.size.y;
        SDL_RenderFillRect(
            Graphics::getSDL(),
            &r
        );
    }
}

void RectDrawSystem::update(World* w, double dt)
{
	for (auto const& entity : _entities)
	{
        auto& rect = w -> getComponent<FRect>(entity);
        rect.pos.x -= dt * rect.size.x;
        rect.pos.y -= dt * rect.size.y;
        rect.pos.x = (rect.pos.x < -rect.size.x) ? 540 + rect.size.x : rect.pos.x;
        rect.pos.y = (rect.pos.y < -rect.size.y) ? 540 + rect.size.x : rect.pos.y;
    }
}