#include <chimera/stat.hpp>

#include <algorithm>

using chimera::StatSource;

namespace
{
    template <typename C>
    auto find_it(C &&c, int id)
    {
        return std::lower_bound(std::begin(c), std::end(c), id, [](auto const &storedStat, auto key) {
            return storedStat.id < key;
        });
    }

    template <typename C, typename FOUND_FN, typename MISSED_FN>
    auto branched_find(C &&c, int id, FOUND_FN && found_fn, MISSED_FN && missed_fn)
    {
        auto it = find_it(c, id);
        if((it != std::end(c)) && (it->id == id))
        {
            return found_fn(it);
        }
        return missed_fn(it);
    }

    template <typename C, typename FOUND_FN>
    auto branched_find(C &&c, int id, FOUND_FN && found_fn)
    {
        return branched_find(c, id, found_fn,
            [](auto it) {
                (void) it;
            }
        );
    }
}

auto StatSource::count() const noexcept -> std::size_t
{
    return _stats.size();
}

auto StatSource::find(int id) const noexcept -> std::optional<int>
{
    return branched_find(_stats, id,
        [](auto it) -> std::optional<int> {
            return it->value;
        },
        [](auto it) -> std::optional<int> {
            (void) it;
            return std::nullopt;
        }
    );
}

void StatSource::remove(int id)
{
    branched_find(_stats, id,
        [this](auto it) {
            _stats.erase(it);
        }
    );
}

void StatSource::set(int id, int value)
{
    branched_find(_stats, id,
        [value](auto it) {
            it->value = value;
        },
        [this, id, value](auto it) {
            _stats.emplace(it, StoredStat{id, value});
        }
    );
}

void StatSource::adjust(int id, int value)
{
    branched_find(_stats, id,
        [value](auto it) {
            it->value += value;
        },
        [this, id, value](auto it) {
            _stats.emplace(it, StoredStat{id, value});
        }
    );
}
