#include <chimera/test/jobs.hpp>

#include <algorithm>
#include <cassert>
#include <unordered_map>

#include <chimera/internal/make_pointer.hpp>

using chimera::test::Jobs;

auto Jobs::get(Id id) noexcept -> ConstPointer<Job>
{
    static std::unordered_map<Id, ConstPointer<Job>> const jobs = {
        {Id::fighter,
         chimera::internal::make_pointer<chimera::Job>(10, "Fighter")},
        {Id::mage, chimera::internal::make_pointer<chimera::Job>(20, "Mage")}};

    auto it = jobs.find(id);
    assert(it != std::end(jobs));
    return it->second;
}
