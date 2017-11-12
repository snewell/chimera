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
    void insert_helper(C &items, chimera::ConstPointer<chimera::Item> const &item, std::size_t count)
    {
        if((items.size() + count) < items.capacity())
        {
            auto it = std::lower_bound(std::begin(items), std::end(items), item->id(), [](auto const &item, auto const id) {
                return item->id() < id;
            });
            while(count != 0)
            {
                --count;
                it = items.insert(it, item);
            }
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

auto chimera::FixedSizeInventory::size() const noexcept -> std::size_t
{
    return _items.size();
}
