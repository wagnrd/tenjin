#include "engine.hpp"

namespace tenjin {
    Engine& Engine::instance() {
        static Engine _instance;
        return _instance;
    }
} // namespace tenjin
