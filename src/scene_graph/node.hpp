#pragma once

#include <memory>
#include <vector>

namespace tenjin {
    class node;

    template<typename T>
    concept node_c = std::is_base_of_v<node, T>;

    class node {

        node* parent_ = nullptr;
        std::vector<std::unique_ptr<node>> children_;

    protected:

    public:
        node() = default;
        node(const node& other) = delete;
        node(node&&) = default;
        node& operator=(const node&) = delete;
        node& operator=(node&&) = default;
        virtual ~node() = default;

        template<node_c T = node, typename... Args>
        [[nodiscard]] static std::unique_ptr<T> create(Args... args) {
            return std::make_unique<T>(std::forward<Args>(args)...);
        }

        [[nodiscard]] std::unique_ptr<node> operator()(std::unique_ptr<node>&& node);
        [[nodiscard]] node* get_parent() const noexcept;
        node& add_node(std::unique_ptr<node>&& node);

        virtual void update() {};
    };
} // namespace tenjin
