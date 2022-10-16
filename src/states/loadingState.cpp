#include "loadingState.hpp"

void loadingState::onInit()
{
    AssetLoader::load("./assets/assetlist.json");
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

    // Show percentage if something loaded
    if(AssetLoader::getPercentage() > 0.1)
        showSimpleMessageBox("Error", Utils::to_string<double>(100 * AssetLoader::getPercentage()) + "%", SDL_MESSAGEBOX_ERROR, Window::getInstance().getSDL());

    // Go to main scene
    if(AssetLoader::getPercentage() == 1)
    {
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
