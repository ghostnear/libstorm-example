#include "mainState.hpp"

void mainState::onInit()
{
    w.saveInstance(new obj_background());
}

void mainState::onDestroy()
{

}

void mainState::draw()
{
    Graphics::clear(50, 100, 155);

    w.draw(this);

    Graphics::update();
}

void mainState::update(double dt)
{
    // Update the world
    w.update(this, dt);

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