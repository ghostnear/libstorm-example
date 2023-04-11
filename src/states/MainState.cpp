#include "MainState.hpp"

void MainState::onInit()
{
    scrollingRectanglesConfig cfg;
    this -> root -> addChild(new scrollingRectangles(cfg), "blue_rectangles");

    FPSTextConfig fpsTextcfg;
    fpsTextcfg.textcfg.size = 32;
    this -> root -> addChild(new FPSText(fpsTextcfg), "fps_text");

    MainTextConfig config;
    this -> root -> addChild(new MainText(config), "main_text");
}

void MainState::onDestroy()
{

}

void MainState::draw()
{
    Graphics::clear(50, 100, 155);

    // Draw scene
    this -> root -> executeAll("draw");

    Graphics::update();
}

void MainState::update(double dt)
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
