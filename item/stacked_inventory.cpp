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
  , _count{count}
{
}

namespace
{
    template <typename C>
    auto find_it(C && c, chimera::ConstPointer<chimera::Item> const & item)
    {
        return std::lower_bound(
            std::begin(c), std::end(c), item->id(),
            [](auto const & slot, auto id) { return slot._item->id() < id; });
    }

    template <typename C>
    void insert_helper(C & items,
                       chimera::ConstPointer<chimera::Item> const & item,
                       std::size_t count, std::size_t stack_limit)
    {
        auto it = find_it(items, item);
        if((it != std::end(items)) && (it->_item->id() == item->id()))
        {
            // slot already exists for item
            auto const new_count = it->_count + count;
            if(new_count <= stack_limit)
            {
                it->_count = new_count;
            }
            else
            {
                throw chimera::Inventory::InsufficentSpaceException{};
            }
        }
        else
        {
            // need to add a new slot
            if((items.size() < items.capacity()) && (count <= stack_limit))
            {
                items.emplace(it, item, count);
            }
            else
            {
                throw chimera::Inventory::InsufficentSpaceException{};
            }
        }
    }
}

void StackedInventory::insert(ConstPointer<Item> const & item)
{
    insert_helper(_items, item, 1, _stack_limit);
    _total_count += 1;
}

void StackedInventory::insert(ConstPointer<Item> const & item,
                              std::size_t count)
{
    insert_helper(_items, item, count, _stack_limit);
    _total_count += count;
}

auto chimera::StackedInventory::size() const noexcept -> std::size_t
{
    return _total_count;
}

auto StackedInventory::count(ConstPointer<Item> const & item) const noexcept
    -> std::size_t
{
    auto const first = find_it(_items, item);
    if((first != std::end(_items)) && (first->_item == item))
    {
        return first->_count;
    }
    return 0;
}

auto StackedInventory::contains(ConstPointer<Item> const & item) const noexcept
    -> bool
{
    auto const first = find_it(_items, item);
    return ((first != std::end(_items)) && (first->_item == item));
}
