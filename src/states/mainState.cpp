#include "mainState.hpp"

void mainState::onInit()
{
    scrollingRectanglesConfig cfg;
    this -> root -> addChild(new scrollingRectangles(cfg), "blue_rectangles");
}

void mainState::onDestroy()
{

}

void mainState::draw()
{
    Graphics::clear(50, 100, 155);

    // Draw scene
    this -> root -> executeAll("draw");

    Graphics::update();
}

void mainState::update(double dt)
{
    // Press escape to close window
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();

    // Update scene
    this -> root -> executeAll("update");

    // Toggle fullscreen
    if(Input::isKeyPressed(SDLK_F11))
    {
        if(!Window::isFullscreen())
            Window::setFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        else
            Window::setFullscreen(0);
    }
}
