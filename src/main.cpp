#include <iostream>

#include "scene_graph/node.hpp"

class character : public tenjin::node {
    node* enemy_;
    std::string name_;

public:
    void update() override {
        std::cout << "Name: " << name_ << '\n';
    }

    void set_enemy(node* enemy) {
        enemy_ = enemy;
    }

    void set_name(const std::string& name) {
        name_ = name;
    }
};

int main() {
    std::cout << "Hello, World!" << '\n';
    auto character_ptr = character::create();
    auto* character_ptr2 = character_ptr.get();

    auto* character = static_cast<class character*>(character_ptr2);
    character->set_name("Character");

    {
        auto scene = tenjin::node::create();
        auto& enemy = static_cast<class character&>(scene->add_node(character::create()));
        enemy.set_name("Enemy");
        character->set_enemy(&enemy);
    }

    character->update();
}
