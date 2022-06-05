#include <libstorm.hpp>

using namespace Storm;

int main(int argc, char* argv[])
{
    // Init and quit on fail
    if(Storm_Init() == EXIT_FAILURE)
        return EXIT_FAILURE;

    printf("Hello World!\n");

    // Quit and return the quit result
    return Storm_Quit();
}