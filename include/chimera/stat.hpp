#ifndef CHIMERA_STAT_HPP
#define CHIMERA_STAT_HPP 1

#include <functional>
#include <optional>
#include <vector>

#include <chimera/identified_object.hpp>
#include <chimera/named_object.hpp>

namespace chimera
{
    class StatSource
    {
    public:
        struct StoredStat
        {
            Identifier id;
            int value;
        };

        auto count() const noexcept -> std::size_t;

        auto find(Identifier id) const noexcept -> std::optional<int>;

        void remove(Identifier id);

        void set(Identifier id, int value);

        void adjust(Identifier id, int value);

    private:
        std::vector<StoredStat> _stats;
    };

    class Stat : private NamedObject, private IdentifiedObject
    {
    public:
        Stat(Identifier id, String name);

        virtual auto get(StatSource const & ss) const noexcept -> int = 0;

        using IdentifiedObject::id;
        using NamedObject::name;
    };

    class BaseStat : public Stat
    {
    public:
        BaseStat(Identifier id, String name, int fallback);

        auto fallback() const noexcept -> int;

        void fallback(int fallback) noexcept;

        auto get(StatSource const & ss) const noexcept -> int override;

    private:
        int _fallback;
    };

    class ComplexStat : public Stat
    {
    public:
        using Calculation = std::function<int(StatSource const &)>;

        ComplexStat(Identifier id, String name, Calculation calculation);

        auto calculation() const noexcept -> Calculation const &;

        void calculation(Calculation const & calculation);

        auto get(StatSource const & ss) const noexcept -> int override;

    private:
        Calculation _calculation;
    };
}

#endif
