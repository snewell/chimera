#include <chimera/battler.hpp>

#include <cassert>

using chimera::Battler;

Battler::Battler(String name, ConstPointer<Job> job)
  : Battler{std::move(name), std::move(job), StatSource{}}
{
}

Battler::Battler(String name, ConstPointer<Job> job, StatSource stats)
  : NamedObject{std::move(name)}
  , _job{std::move(job)}
  , _stats{std::move(stats)}
{
    assert(_job);
}

auto Battler::job() const noexcept -> ConstPointer<Job> const &
{
    return _job;
}

void Battler::job(ConstPointer<Job> const & job)
{
    _job = job;
}

auto Battler::stats() noexcept -> StatSource &
{
    return _stats;
}

auto Battler::stats() const noexcept -> StatSource const &
{
    return _stats;
}
