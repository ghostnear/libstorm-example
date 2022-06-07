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

    // Create game manager
    GameManager g;
    g.pushState(new mainState());

    // Main loop
    while(!Window::shouldClose())
    {
        // Poll events
        Input::pollEvents();

        // Update
        g.update(0);

        // Draw
        g.draw();
    }

    // Quit and return the quit result
    return StormQuit();
}