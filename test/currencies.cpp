#include <chimera/test/currencies.hpp>

#include <algorithm>
#include <cassert>
#include <unordered_map>

#include <chimera/internal/make_pointer.hpp>

using chimera::test::Currencies;

auto Currencies::get(Id id) noexcept -> ConstPointer<Currency>
{
    static std::unordered_map<Id, ConstPointer<Currency>> const currencies = {
        {Id::gold,
         chimera::internal::make_pointer<chimera::Currency>(10, "Gold", 2.0)},
        {Id::silver,
         chimera::internal::make_pointer<chimera::Currency>(20, "Silver", 1.5)},
        {Id::bronze, chimera::internal::make_pointer<chimera::Currency>(
                         30, "Bronze", 1.0)}};

    auto it = currencies.find(id);
    assert(it != std::end(currencies));
    return it->second;
}
