#include "LoadingState.hpp"

void LoadingState::on_init()
{
    LoadingBarConfig cfg;
    root->addChild(new LoadingBar(cfg), "loading_bar");

    AssetLoader::load("./assets/assetlist.json");
    AssetLoader::start();
}

void LoadingState::on_destroy()
{

}

void LoadingState::draw()
{
    Graphics::clear(0, 0, 0);

    // Draw scene
    root->executeAll("draw");

    Graphics::update();
}

void LoadingState::update(double dt)
{
    // Press escape to close window
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();

    // Update scene
    root->executeAll("update");

    // Go to main scene after waiting for thread to stop
    if(AssetLoader::getPercentage() == 1)
    {
        AssetLoader::finish();
        GameManager::popState();
        GameManager::pushState(new MainState());
    }

    // Toggle fullscreen
    if(Input::isKeyPressed(SDLK_F11))
    {
        if(!Window::isFullscreen())
            Window::setFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
        else
            Window::setFullscreen(0);
    }
}
