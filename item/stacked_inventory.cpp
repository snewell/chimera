#include <chimera/inventory.hpp>

#include <algorithm>

using chimera::StackedInventory;

StackedInventory::StackedInventory(std::size_t capacity, std::size_t stackLimit)
  : _stack_limit{stackLimit}
  , _total_count{0}
{
    _items.reserve(capacity);
}

StackedInventory::Slot::Slot(ConstPointer<Item> item, std::size_t count)
  : _item{std::move(item)}
  , _count{count} { }

namespace
{
    template <typename C>
    void insert_helper(C &items, chimera::ConstPointer<chimera::Item> const &item, std::size_t count)
    {
        auto const end = std::end(items);
        auto it = std::lower_bound(std::begin(items), end, item->id(), [](auto const &slot, auto const id) {
            return slot._item->id() < id;
        });
        if((it != end) && (it->_item->id() == item->id()))
        {
            // slot already exists for item
            it->_count += count;
        }
        else
        {
            // need to add a new slot
            if((items.size() + count) < items.capacity())
            {
                items.emplace(it, item, count);
            }
        }
    }
}

void StackedInventory::insert(ConstPointer<Item> const &item)
{
    insert_helper(_items, item, 1);
    _total_count += 1;
}

void StackedInventory::insert(ConstPointer<Item> const &item, std::size_t count)
{
    insert_helper(_items, item, count);
    _total_count += count;
}

auto chimera::StackedInventory::size() const noexcept -> std::size_t
{
    return _total_count;
}
