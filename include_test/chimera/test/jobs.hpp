#ifndef CHIMERA_TEST_JOBS_HPP
#define CHIMERA_TEST_JOBS_HPP 1

#include <chimera/job.hpp>

namespace chimera::test
{
    class Jobs
    {
    public:
        enum class Id
        {
            fighter,
            mage
        };

        static auto get(Id id) noexcept -> ConstPointer<Job>;
    };
}

#endif
