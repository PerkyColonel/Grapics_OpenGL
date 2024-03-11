#include "engine.h"

int main()
{
    Engine engine(1200, 720, "Testing");

    if (!engine.Initialize())
    {
        std::cout << std::endl
                  << "Press any key to close program..." << std::endl;
        std::cin.get();
    };
}
