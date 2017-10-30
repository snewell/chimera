#ifndef CHIMERA_EQUIPMENT_HPP
#define CHIMERA_EQUIPMENT_HPP 1

#include <chimera/item.hpp>
#include <chimera/stat.hpp>

namespace chimera
{
    class Equipment : public Item
    {
    public:
        Equipment(Identifier id,
                  String name,
                  int value,
                  String description);

        auto stats() const noexcept -> StatSource const&;

        auto stats() -> StatSource&;

    private:
        StatSource _stats;
    };
}

#endif
