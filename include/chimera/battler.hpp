#ifndef CHIMERA_BATTLER_HPP
#define CHIMERA_BATTLER_HPP 1

#include <chimera/job.hpp>
#include <chimera/named_object.hpp>

namespace chimera
{
    class Battler : private NamedObject
    {
    public:
        Battler(String name, ConstPointer<Job> job);

        auto job() const noexcept -> ConstPointer<Job> const &;

        void job(ConstPointer<Job> const & job);

        using NamedObject::name;

    private:
        ConstPointer<Job> _job;
    };
}

#endif
