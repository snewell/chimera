#include <chimera/test/items.hpp>

#include <algorithm>
#include <cassert>
#include <unordered_map>

#include <chimera/internal/make_pointer.hpp>

using chimera::test::Items;

auto Items::get(Id id) noexcept -> ConstPointer<Item>
{
    static std::unordered_map<Id, ConstPointer<Item>> const items = {
        {Id::potion, chimera::internal::make_pointer<chimera::Item>(
                         10, "Potion", 20, "Heal some HP")}};

    auto it = items.find(id);
    assert(it != std::end(items));
    return it->second;
}
