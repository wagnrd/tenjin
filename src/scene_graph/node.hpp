#pragma once

#include <concepts>
#include <memory>
#include <vector>

namespace tenjin {
    class BaseNode {

        BaseNode* parent_ = nullptr;
        std::vector<std::shared_ptr<BaseNode>> children_;

    public:
        BaseNode() = default;
        BaseNode(const BaseNode& other) = delete;
        BaseNode(BaseNode&&) = default;
        BaseNode& operator=(const BaseNode&) = delete;
        BaseNode& operator=(BaseNode&&) = default;
        virtual ~BaseNode() = default;

        [[nodiscard]] BaseNode* parent() const noexcept;

        virtual void update() {
        }

    private:
        template<class Child>
        [[nodiscard]] std::weak_ptr<Child> add_node(std::unique_ptr<Child>&& child) {
            parent_ = child.get();
            std::shared_ptr<Child> child_sp = std::move(child);
            std::weak_ptr<Child> child_wp = child_sp;
            children_.push_back(std::move(child_sp));

            return child_wp;
        }

        template<class Derived>
        friend class Node;
    };

    template<class Derived = BaseNode>
    class Node : public BaseNode {

    public:
        template<typename... Args>
            requires std::constructible_from<Derived, Args...>
        [[nodiscard]] static std::unique_ptr<Derived> create(Args... args) {
            return std::make_unique<Derived>(args...);
        }

        template<class Child>
            requires std::derived_from<Child, BaseNode>
        [[nodiscard]] std::weak_ptr<Child> add_node(std::unique_ptr<Child>&& child) {
            return BaseNode::add_node<Child>(std::move(child));
        }

        template<typename... Args, class Child>
            requires std::constructible_from<Child, Args...>
        [[nodiscard]] std::weak_ptr<Child> emplace_node(Args... args) {
            return BaseNode::add_node(std::make_unique<Child>(std::forward<Args>(args)...));
        }
    };

} // namespace tenjin
