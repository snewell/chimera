#ifndef CHIMERA_BATTLER_HPP
#define CHIMERA_BATTLER_HPP 1

#include <chimera/job.hpp>
#include <chimera/named_object.hpp>
#include <chimera/stat.hpp>

namespace chimera
{
    class Battler : private NamedObject
    {
    public:
        Battler(String name, ConstPointer<Job> job);

        Battler(String name, ConstPointer<Job> job, StatSource stats);

        auto job() const noexcept -> ConstPointer<Job> const &;

        void job(ConstPointer<Job> const & job);

        auto stats() noexcept -> StatSource &;

        auto stats() const noexcept -> StatSource const &;

        using NamedObject::name;

    private:
        ConstPointer<Job> _job;
        StatSource _stats;
    };
}

#endif
