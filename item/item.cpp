#include <chimera/item.hpp>
#include <chimera/inventory.hpp>

using chimera::Item;

Item::Item(Identifier id, String name, int value, String description)
  : NamedObject{std::move(name)}
  , IdentifiedObject{id}
  , _description{std::move(description)}
  , _value{value}
{
}

auto Item::value() const noexcept -> int
{
    return _value;
}

void Item::value(int value) noexcept
{
    _value = value;
}

auto Item::description() const noexcept -> String const &
{
    return _description;
}

void Item::description(String const & description)
{
    _description = description;
}

using chimera::Inventory;

void Inventory::insert(ConstPointer<Item> const &item, std::size_t count)
{
    while(count != 0)
    {
        --count;
        insert(item);
    }
}
