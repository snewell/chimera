#ifndef CHIMERA_TEST_CURRENCIES_HPP
#define CHIMERA_TEST_CURRENCIES_HPP 1

#include <chimera/currency.hpp>

namespace chimera::test
{
    class Currencies
    {
    public:
        enum class Id
        {
            gold,
            silver,
            bronze
        };

        static auto get(Id id) noexcept -> ConstPointer<Currency>;
    };
}

#endif
