#ifndef CHIMERA_TEST_STATS_HPP
#define CHIMERA_TEST_STATS_HPP 1

#include <chimera/stat.hpp>

namespace chimera::test
{
    class Stats
    {
    public:
        enum class Id
        {
            strength
        };

        static auto get(Id id) noexcept -> ConstPointer<Stat>;
    };
}

#endif
