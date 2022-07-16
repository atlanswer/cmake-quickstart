#include <iostream>
#include <fmt/core.h>

#include "libName/libName.hpp"

int main(int argc, char **argv) {
  // std::cout << "Hello, world!"
            // << " from libName version " << libName::VERSION << ".\n";
  fmt::print("The answer is {}.", 42);
  return 0;
}
