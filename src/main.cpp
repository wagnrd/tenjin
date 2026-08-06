#include <iostream>

#include "renderers/terminal/terminal.hpp"

int main() {
    Terminal terminal{};
    const auto size = terminal.get_size();
    std::cout << "Terminal size: " << size.x << "x" << size.y << '\n';
}
