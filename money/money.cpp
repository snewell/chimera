#include <chimera/money.hpp>

#include <cassert>

using chimera::Money;

Money::Money(ConstPointer<Currency> currency, int amount)
  : _currency{std::move(currency)}
  , _amount{amount}
{
    assert(_currency);
}

auto Money::currency() const noexcept -> ConstPointer<Currency> const &
{
    return _currency;
}

void Money::currency(ConstPointer<Currency> const & currency)
{
    assert(currency);
    _currency = currency;
}

auto Money::amount() const noexcept -> int
{
    return _amount;
}

void Money::amount(int amount)
{
    _amount = amount;
}

auto Money::value() const noexcept -> int
{
    return _currency->value() * _amount;
}

auto Money::convert(ConstPointer<Currency> const & currency) -> Money
{
    auto const to_ratio = _currency->value() / currency->value();
    auto const from_ratio = currency->value() / _currency->value();

    auto const to_amount = static_cast<int>(_amount * to_ratio);
    auto const local_amount =
        _amount - static_cast<int>(to_amount * from_ratio);

    _amount = local_amount;
    return Money{currency, static_cast<int>(to_amount)};
}

auto Money::convert_amount(ConstPointer<Currency> const & currency) const
    noexcept -> int
{
    auto const ratio = _currency->value() / currency->value();
    return _amount * ratio;
}
