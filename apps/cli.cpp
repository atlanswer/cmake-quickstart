#include <iostream>

#include "libName/libName.hpp"

int main(int argc, char** argv) {
    std::cout << "Hello, world!"
    << " from libName version " << libName::VERSION << ".\n";
    return 0;
}
