#ifndef CHIMERA_NAMED_OBJECT_HPP
#define CHIMERA_NAMED_OBJECT_HPP 1

#include <chimera/types.hpp>

namespace chimera
{
    class NamedObject
    {
    public:
        explicit NamedObject(String name);

        auto name() const noexcept -> String const &;

        void name(String const & name);

    private:
        String _name;
    };
}

#endif
