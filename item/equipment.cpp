#include <chimera/equipment.hpp>

using chimera::Equipment;

Equipment::Equipment(Identifier id, String name, int value, String description)
  : Item{id, std::move(name), value, std::move(description)}
{
}

auto Equipment::stats() const noexcept -> StatSource const &
{
    return _stats;
}

auto Equipment::stats() -> StatSource &
{
    return _stats;
}
