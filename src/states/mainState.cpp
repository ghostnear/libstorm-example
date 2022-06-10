#include "mainstate.hpp"

void mainState::onInit()
{
    offset = 0;
}

void mainState::onDestroy()
{

}

void mainState::draw(GameManager* gm)
{
    Graphics::clear(50, 100, 155);

    SDL_Rect r;
    auto size = Window::getSize();

    for(int32_t i = 0; i <= size.first / 54 + 1; i++)
        for(int32_t j = 0; j <= size.second / 54 + 1; j++)
            if(i % 2 == j % 2)
            {
                SDL_SetRenderDrawColor(Graphics::getSDL(), 50, 130, 155, 255);
                r.x = i * 54 + offset;
                r.y = j * 54 + offset;
                r.w = 54;
                r.h = 54;
                SDL_RenderFillRect(Graphics::getSDL(), &r);
            }

    Graphics::update();
}

void mainState::update(GameManager* gm, double dt)
{
    // Offset clamping
    offset -= 54 * dt;
    if(offset < -54)
        offset += 54;

    // Press escape to close window
    if(Input::isReleased(SDLK_ESCAPE))
        Window::close();

    // Toggle fullscreen
    if(Input::isPressed(SDLK_F11))
    {
        if(!Window::isFullscreen())
            Window::setFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        else
            Window::setFullscreen(0);
    }       
}