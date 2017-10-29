#include <chimera/named_object.hpp>

using chimera::NamedObject;

NamedObject::NamedObject(String name)
  : _name{std::move(name)} { }

auto NamedObject::name() const noexcept -> String const&
{
    return _name;
}

void NamedObject::name(String const &name)
{
    _name = name;
}
