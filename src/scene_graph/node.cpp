#include "node.hpp"

namespace tenjin {
    BaseNode* BaseNode::parent() const noexcept {
        return parent_;
    }
} // namespace tenjin
