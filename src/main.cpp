#include <libstorm.hpp>

using namespace Storm;

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(StormInit() == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Set metadata
    Window::setName("Example app");

    // Main loop
    while(!Window::shouldClose())
    {
        // Poll events
        Input::pollEvents();

        // Update

        // Draw
        Graphics::clear(0, 0, 0);
        Graphics::update();
    }

    // Quit and return the quit result
    return StormQuit();
}