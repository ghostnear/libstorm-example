#include "MainState.hpp"

void MainState::on_init()
{
    ScrollingRectanglesConfig cfg;
    root->addChild(new ScrollingRectangles(cfg), "blue_rectangles");

    FPSTextConfig fpsTextcfg;
    fpsTextcfg.textcfg.size = 32;
    root->addChild(new FPSText(fpsTextcfg), "fps_text");

    MainTextConfig config;
    root->addChild(new MainText(config), "main_text");
}

void MainState::on_destroy()
{

}

void MainState::draw()
{
    Graphics::clear(50, 100, 155);

    // Draw scene
    root->executeAll("draw");

    Graphics::update();
}

void MainState::update(double dt)
{
    // Press escape to close window
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();

    // Update scene
    root->executeAll("update");

    // Toggle fullscreen
    if(Input::isKeyPressed(SDLK_F11))
    {
        if(!Window::isFullscreen())
            Window::setFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        else
            Window::setFullscreen(0);
    }
}
