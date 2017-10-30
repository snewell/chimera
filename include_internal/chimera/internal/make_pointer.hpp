#ifndef CHIMERA_INTERNAL_MAKE_POINTER_HPP
#define CHIMERA_INTERNAL_MAKE_POINTER_HPP 1

#include <chimera/types.hpp>

namespace chimera::internal
{
    template <typename T, typename ...Ts>
    auto make_pointer(Ts && ...ts)
    {
        return std::make_shared<T>(std::forward<Ts>(ts)...);
    }
}

#endif
