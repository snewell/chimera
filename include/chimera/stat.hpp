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

        std::optional<int> find(int id) const noexcept;

        void remove(int id);

        void set(int id, int value);

        void adjust(int id, int value);

    private:
        std::vector<StoredStat> _stats;
    };
}

#endif
