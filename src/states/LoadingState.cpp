#include "LoadingState.hpp"

using namespace Storm;

void LoadingState::on_init()
{
    root->add_child(new LoadingBar({}), "loading_bar");

    AssetLoader::load("./assets/assetlist.json");
    AssetLoader::start();
}

void LoadingState::update()
{
    // Press escape to close window
#ifndef VITA
    if(Input::isKeyReleased(SDLK_ESCAPE))
        Window::close();
#endif

    // Update scene
    root->execute_all("update");

    // Go to main scene after waiting for thread to stop
    if(AssetLoader::get_percentage() == 1)
    {
        AssetLoader::finish();
        GameManager::pop_state();
        GameManager::push_state(new MainState());
    }
}
