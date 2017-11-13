#ifndef CHIMERA_TEST_ITEMS_HPP
#define CHIMERA_TEST_ITEMS_HPP 1

#include <chimera/item.hpp>

namespace chimera::test
{
    class Items
    {
    public:
        enum class Id
        {
            potion
        };

        static auto get(Id id) noexcept -> ConstPointer<Item>;
    };
}

#endif
