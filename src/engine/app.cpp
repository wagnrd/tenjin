#include "app.hpp"

#include <iostream>
#include <SDL3/SDL_main.h>

#include "engine.hpp"
#include "SDL3/SDL_events.h"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
    std::cout << "SDL_AppInit\n";

    tenjin::Engine::instance();
    int setup_result = tenjin_main();

    if (setup_result != 0) {
        return SDL_AppResult::SDL_APP_FAILURE;
    }

    return SDL_AppResult::SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    return SDL_AppResult::SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    std::cout << "SDL_AppEvent: " << event->type << "\n";

    if (event->type == SDL_EventType::SDL_EVENT_QUIT) {
        return SDL_AppResult::SDL_APP_SUCCESS;
    }

    return SDL_AppResult::SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    std::cout << "SDL_AppQuit\n";
}
