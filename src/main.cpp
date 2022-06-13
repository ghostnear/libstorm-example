#include <libstorm.hpp>
#include "states/states.hpp"

using namespace Storm;

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(StormInit() == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Set metadata
    Window::setName("Example");

    // Push the default state to the manager
    GameManager::pushState(new mainState());

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
    return StormQuit(0);
}