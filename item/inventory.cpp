#include <chimera/inventory.hpp>

using chimera::Inventory;

void Inventory::insert(ConstPointer<Item> const &item, std::size_t count)
{
    while(count != 0)
    {
        --count;
        insert(item);
    }
}

auto Inventory::contains(ConstPointer<Item> const &item) const noexcept -> bool
{
    return (count(item) != 0);
}
