#include "node.hpp"

#include <memory>

namespace tenjin {
    std::unique_ptr<node> node::operator()(std::unique_ptr<node>&& node) {
        add_node(std::move(node));
    }

    node& node::add_node(std::unique_ptr<node>&& node) {
        auto* child = node.get();
        node->parent_ = this;
        children_.push_back(std::move(node));

        return *child;
    }
} // namespace tenjin
