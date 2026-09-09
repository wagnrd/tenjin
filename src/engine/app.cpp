#include "app.hpp"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
    return SDL_AppResult::SDL_APP_SUCCESS;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    return SDL_AppResult::SDL_APP_SUCCESS;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    return SDL_AppResult::SDL_APP_SUCCESS;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
}
