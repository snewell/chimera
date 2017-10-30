#ifndef CHIMERA_CURRENCY_HPP
#define CHIMERA_CURRENCY_HPP 1

#include <chimera/identified_object.hpp>
#include <chimera/named_object.hpp>

namespace chimera
{
    class Currency : private NamedObject,
                     private IdentifiedObject
    {
    public:
        Currency(Identifier id,
                 String name,
                 double value);

        auto value() const noexcept -> double;

        void value(double value);

        using IdentifiedObject::id;
        using NamedObject::name;

    private:
        double _value;
    };
}

#endif
