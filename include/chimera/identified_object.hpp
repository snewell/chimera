#ifndef CHIMERA_IDENTIFIED_OBJECT_HPP
#define CHIMERA_IDENTIFIED_OBJECT_HPP 1

#include <chimera/types.hpp>

namespace chimera
{
    class IdentifiedObject
    {
    public:
        IdentifiedObject(Identifier id);

        auto id() const noexcept -> Identifier;

        void id(Identifier id) noexcept;

    private:
        Identifier _id;
    };
}

#endif
