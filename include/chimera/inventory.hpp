#ifndef CHIMERA_INVENTORY_HPP
#define CHIMERA_INVENTORY_HPP 1

#include <chimera/item.hpp>

#include <vector>

namespace chimera
{
    class Inventory
    {
    public:
        virtual void insert(ConstPointer<Item> const &item) = 0;

        virtual void insert(ConstPointer<Item> const &item, std::size_t count);

        virtual auto size() const noexcept -> std::size_t = 0;

        virtual auto count(ConstPointer<Item> const &item) const noexcept -> std::size_t = 0;

        virtual auto contains(ConstPointer<Item> const &item) const noexcept -> bool;
    };

    class FixedSizeInventory : public Inventory
    {
    public:
        FixedSizeInventory(std::size_t capacity);

        void insert(ConstPointer<Item> const &item) override;

        void insert(ConstPointer<Item> const &item, std::size_t count) override;

        auto size() const noexcept -> std::size_t override;

        auto count(ConstPointer<Item> const &item) const noexcept -> std::size_t override;

        auto contains(ConstPointer<Item> const &item) const noexcept -> bool override;

    private:
        std::vector<ConstPointer<Item>> _items;
    };

    class StackedInventory : public Inventory
    {
    public:
        StackedInventory(std::size_t capacity, std::size_t stackLimit);

        void insert(ConstPointer<Item> const &item) override;

        void insert(ConstPointer<Item> const &item, std::size_t count) override;

        auto size() const noexcept -> std::size_t override;

        auto count(ConstPointer<Item> const &item) const noexcept -> std::size_t override;

    private:
        struct Slot
        {
            Slot(ConstPointer<Item> item, std::size_t count);

            ConstPointer<Item> _item;
            std::size_t _count;
        };

        std::vector<Slot> _items;
        std::size_t _stack_limit;
        std::size_t _total_count;
    };
}

#endif
