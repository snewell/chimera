#ifndef CHIMERA_JOB_HPP
#define CHIMERA_JOB_HPP 1

#include <chimera/identified_object.hpp>
#include <chimera/named_object.hpp>

namespace chimera
{
    class Job : private NamedObject, private IdentifiedObject
    {
    public:
        Job(Identifier id, String name);

        using IdentifiedObject::id;
        using NamedObject::name;
    };
}

#endif
