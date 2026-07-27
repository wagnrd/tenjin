#include <iostream>
#include "terminal_graphics/terminal.hpp"

int main() {
    const auto size = Terminal::get_size();
    std::cout << "Terminal size: " << size.x << "x" << size.y << std::endl;
}
