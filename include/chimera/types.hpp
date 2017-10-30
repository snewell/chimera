#ifndef CHIMERA_TYPES_HPP
#define CHIMERA_TYPES_HPP 1

#include <cstdint>
#include <memory>
#include <string>

namespace chimera
{
    template <typename T>
    using ConstPointer = std::shared_ptr<T const>;

    using Identifier = std::uint32_t;

    template <typename T>
    using Pointer = std::shared_ptr<T>;

    using String = std::string;
}

#endif
