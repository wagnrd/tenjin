#include <iostream>
#include <utility>

#include "scene_graph/node.hpp"

class Character : public tenjin::Node<Character> {

    std::string name_;

public:
    explicit Character(std::string name) :
        name_(std::move(name)) {
    }

    void test() {
        std::cout << "Character name: " << name_ << '\n';
    }
};

int main() {
    tenjin::Node scene{};
    auto character_up = Character::create("Bob");
    auto character_wp = scene.add_node(std::move(character_up));
    auto character = character_wp.lock();
    character->test();
}
