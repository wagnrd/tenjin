#include "glm/ext/vector_int2.hpp"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <sys/ioctl.h>
#endif

class Terminal {

#if defined(_WIN32)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
#elif defined(__linux__) || defined(__APPLE__)
    struct winsize w;
#endif

public:
    [[nodiscard]] glm::ivec2 get_size();
};
