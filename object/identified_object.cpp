#include <chimera/identified_object.hpp>

using chimera::IdentifiedObject;

IdentifiedObject::IdentifiedObject(Identifier id)
  : _id{id}
{
}

auto IdentifiedObject::id() const noexcept -> Identifier
{
    return _id;
}

void IdentifiedObject::id(Identifier id) noexcept
{
    _id = id;
}
