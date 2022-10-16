#include <libstorm.hpp>
#include "states/states.hpp"

using namespace Storm;

// The role of this example is mostly to show how to make a window and manage states.
// It is also used as a base for anything else.

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(StormInit() == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Set metadata
    Window::setName("libStorm Example");

    // Push the default state to the manager
    // TODO: replace this with a config system to make everything customizable
#ifdef BUILD_TYPE_VITA
    GameManager::limitFPS(60);
#else
    GameManager::limitFPS(160);
#endif

    GameManager::pushState(new loadingState());

    // Main loop
    while(!Window::shouldClose() && GameManager::isRunning())
    {
        // Poll events
        Input::pollEvents();

        // Update
        GameManager::update();

        // Draw
        if(!Window::isMinimized())
            GameManager::draw();
    }

    // Quit and return the quit result
    return StormQuit(EXIT_SUCCESS);
}
