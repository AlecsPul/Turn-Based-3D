#include "Core/Application.h"
#include <iostream>
#include <exception>

int main(int argc, char* argv[]) {
    try {
        Application app;
        app.Run();
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
