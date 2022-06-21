#include "mainState.hpp"

void mainState::onInit()
{
    w.saveInstance(new obj_background());
    w.saveInstance(new obj_menutext());
    w.saveInstance(new obj_fpstext());
}

void mainState::onDestroy()
{

}

void mainState::draw()
{
    Graphics::clear(50, 100, 155);

    // Draw the world
    w.draw(this);

    Graphics::update();
}

void mainState::update(double dt)
{
    // Update the world
    w.update(this, dt);

    // Press escape to close window
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();

    // Toggle fullscreen
    if(Input::isKeyPressed(SDLK_F11))
    {
        if(!Window::isFullscreen())
            Window::setFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        else
            Window::setFullscreen(0);
    }       
}