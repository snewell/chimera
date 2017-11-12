#include <chimera/inventory.hpp>

#include <algorithm>

using chimera::FixedSizeInventory;

FixedSizeInventory::FixedSizeInventory(std::size_t capacity)
{
    _items.reserve(capacity);
}

namespace
{
    template <typename C>
    auto lower_helper(C && c, chimera::ConstPointer<chimera::Item> const &item)
    {
        return std::lower_bound(std::begin(c), std::end(c), item->id(),
                                [](auto const & it, auto id) {
                                    return it->id() < id;
                                });
    }

    template <typename C>
    auto upper_helper(C && c, chimera::ConstPointer<chimera::Item> const &item)
    {
        return std::upper_bound(std::begin(c), std::end(c), item->id(),
                                [](auto id, auto const & it) {
                                    return id < it->id();
                                });
    }

    template <typename C>
    void insert_helper(C &items, chimera::ConstPointer<chimera::Item> const &item, std::size_t count)
    {
        if((items.size() + count) < items.capacity())
        {
            auto it = lower_helper(items, item);
            while(count != 0)
            {
                --count;
                it = items.insert(it, item);
            }
        }
        else
        {
            throw chimera::Inventory::InsufficentSpaceException{};
        }
    }
}

void FixedSizeInventory::insert(ConstPointer<Item> const &item)
{
    insert_helper(_items, item, 1);
}

void FixedSizeInventory::insert(ConstPointer<Item> const &item, std::size_t count)
{
    insert_helper(_items, item, count);

}

auto FixedSizeInventory::size() const noexcept -> std::size_t
{
    return _items.size();
}

auto FixedSizeInventory::count(ConstPointer<Item> const &item) const noexcept -> std::size_t
{
    auto const first = lower_helper(_items, item);
    auto const last = upper_helper(_items, item);
    return std::distance(first, last);
}

auto FixedSizeInventory::contains(ConstPointer<Item> const &item) const noexcept -> bool
{
    auto const first = lower_helper(_items, item);

    if((first != std::end(_items)) && ((*first) == item))
    {
        return true;
    }
    return false;
}
