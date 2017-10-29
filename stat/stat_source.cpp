#include <chimera/stat.hpp>

#include <algorithm>

using chimera::StatSource;

namespace
{
    template <typename C>
    auto find_it(C &&c, int id)
    {
        auto const e = std::end(c);
        return std::find_if(std::begin(c), e, [id](auto const &storedStat) {
            return storedStat.id == id;
        });
    }
}

auto StatSource::find(int id) const noexcept -> std::optional<int>
{
    auto it = find_it(_stats, id);
    if(it != std::end(_stats))
    {
        return it->value;
    }
    return std::nullopt;
}

void StatSource::remove(int id)
{
    auto it = find_it(_stats, id);
    if(it != std::end(_stats))
    {
        _stats.erase(it);
    }
}

void StatSource::set(int id, int value)
{
    auto it = find_it(_stats, id);
    if(it != std::end(_stats))
    {
        it->value = value;
    }
    else
    {
        _stats.emplace(it, StoredStat{id, value});
    }
}

void StatSource::adjust(int id, int value)
{
    auto it = find_it(_stats, id);
    if(it != std::end(_stats))
    {
        it->value += value;
    }
    else
    {
        _stats.emplace(it, StoredStat{id, value});
    }
}
