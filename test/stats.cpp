#include <chimera/test/stats.hpp>

#include <algorithm>
#include <cassert>
#include <unordered_map>

#include <chimera/internal/make_pointer.hpp>

using chimera::test::Stats;

auto Stats::get(Id id) noexcept -> ConstPointer<Stat>
{
    static std::unordered_map<Id, ConstPointer<Stat>> const stats = {
        {Id::strength, chimera::internal::make_pointer<chimera::BaseStat>(
                           10, "Strength", 0)}};

    auto it = stats.find(id);
    assert(it != std::end(stats));
    return it->second;
}
