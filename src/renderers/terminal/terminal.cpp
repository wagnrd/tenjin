#include "terminal.hpp"

#ifdef _WIN32
#    define WIN32_LEAN_AND_MEAN
#    define VC_EXTRALEAN
#    include <Windows.h>
#elif defined(__linux__) || defined(__APPLE__)
#    include <sys/ioctl.h>
#endif
#include <cstdio>
#include <glm/vec2.hpp>

glm::ivec2 Terminal::get_dimensions() {
#ifdef _WIN32
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return {csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1};
#elif defined(__linux__) || defined(__APPLE__)
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    return {w.ws_col, w.ws_row};
#endif
}
