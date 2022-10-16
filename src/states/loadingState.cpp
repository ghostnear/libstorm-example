#include "loadingState.hpp"

void loadingState::onInit()
{
    AssetLoader::load("./assets/assetlist.json");
    AssetLoader::start();
}

void loadingState::onDestroy()
{

}

void loadingState::draw()
{
    Graphics::clear(0, 0, 0);

    // Draw scene
    this -> root -> executeAll("draw");

    Graphics::update();
}

void loadingState::update(double dt)
{
    // Press escape to close window
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();

    // Update scene
    this -> root -> executeAll("update");

    // Go to main scene after waiting for thread to stop
    if(AssetLoader::getPercentage() == 1)
    {
        AssetLoader::finish();
        GameManager::popState();
        GameManager::pushState(new mainState());
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
