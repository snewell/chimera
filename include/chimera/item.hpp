#ifndef CHIMERA_ITEM_HPP
#define CHIMERA_ITEM_HPP 1

#include <chimera/identified_object.hpp>
#include <chimera/named_object.hpp>

namespace chimera
{
    class Item : private NamedObject,
                 private IdentifiedObject
    {
    public:
        Item(Identifier id,
             String name,
             int value,
             String description);

        auto value() const noexcept -> int;

        void value(int) noexcept;

        auto description() const noexcept -> String const&;

        void description(String const &description);

        using NamedObject::name;
        using IdentifiedObject::id;

    private:
        String _description;
        int _value;
    };
}

#endif
