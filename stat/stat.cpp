#include <chimera/stat.hpp>

using chimera::Stat;

Stat::Stat(Identifier id, String name)
  : NamedObject{std::move(name)}
  , IdentifiedObject{id}
{
}

using chimera::BaseStat;

BaseStat::BaseStat(Identifier id, String name, int fallback)
  : Stat{id, std::move(name)}
  , _fallback{fallback}
{
}

auto BaseStat::fallback() const noexcept -> int
{
    return _fallback;
}

void BaseStat::fallback(int fallback) noexcept
{
    _fallback = fallback;
}

auto BaseStat::get(StatSource const & ss) const noexcept -> int
{
    auto const val = ss.find(id());

    if(val)
    {
        return *val;
    }
    return _fallback;
}

using chimera::ComplexStat;

ComplexStat::ComplexStat(Identifier id, String name, Calculation calculation)
  : Stat{id, std::move(name)}
  , _calculation{std::move(calculation)}
{
}

auto ComplexStat::calculation() const noexcept -> Calculation const &
{
    return _calculation;
}

void ComplexStat::calculation(Calculation const & calculation)
{
    _calculation = calculation;
}

auto ComplexStat::get(StatSource const & ss) const noexcept -> int
{
    return _calculation(ss);
}
