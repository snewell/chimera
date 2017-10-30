#include <chimera/currency.hpp>

using chimera::Currency;

Currency::Currency(Identifier id,
                   String name,
                   double value)
  : NamedObject{std::move(name)},
    IdentifiedObject{id},
    _value{value} { }

auto Currency::value() const noexcept -> double
{
    return _value;
}

void Currency::value(double value)
{
    _value = value;
}
