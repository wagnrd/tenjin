#pragma once

namespace tenjin {
    class Engine final {
    public:
        Engine(const Engine&) = delete;
        Engine(Engine&&) = default;
        Engine& operator=(const Engine&) = delete;
        Engine& operator=(Engine&&) = default;
        ~Engine() = default;

        static Engine& instance();

    private:
        Engine() = default;
    };
} // namespace tenjin
