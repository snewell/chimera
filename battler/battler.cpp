#include <chimera/battler.hpp>

#include <cassert>

using chimera::Battler;

Battler::Battler(String name,
                 ConstPointer<Job> job)
  : NamedObject{std::move(name)},
    _job{std::move(job)}
{
    assert(_job);
}

auto Battler::job() const noexcept -> ConstPointer<Job> const&
{
    return _job;
}

void Battler::job(ConstPointer<Job> const &job)
{
    _job = job;
}
