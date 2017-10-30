#ifndef CHIMERA_STAT_HPP
#define CHIMERA_STAT_HPP 1

#include <optional>
#include <vector>

namespace chimera
{
    class StatSource
    {
    public:
        struct StoredStat
        {
            int id;
            int value;
        };

        auto count() const noexcept -> std::size_t;

        auto find(int id) const noexcept -> std::optional<int>;

        void remove(int id);

        void set(int id, int value);

        void adjust(int id, int value);

    private:
        std::vector<StoredStat> _stats;
    };
}

#endif
