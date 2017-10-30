#ifndef CHIMERA_MONEY_HPP
#define CHIMERA_MONEY_HPP 1

#include <chimera/currency.hpp>

namespace chimera
{
    class Money
    {
    public:
        Money(ConstPointer<Currency> currency,
              int amount);

        auto currency() const noexcept -> ConstPointer<Currency> const&;

        void currency(ConstPointer<Currency> const &currency);

        auto amount() const noexcept -> int;

        void amount(int amount);

        auto value() const noexcept -> int;

        auto convert(ConstPointer<Currency> currency) -> Money;

        auto convert_amount(ConstPointer<Currency> currency) const noexcept -> int;

    private:
        ConstPointer<Currency> _currency;
        int _amount;
    };
}

#endif
