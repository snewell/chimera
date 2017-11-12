#include <gtest/gtest.h>

#include <chimera/inventory.hpp>
#include <chimera/internal/make_pointer.hpp>

namespace
{
    class SimpleInventory : public chimera::Inventory
    {
    public:
        SimpleInventory()
          : _inventory{10} { }

        void insert(chimera::ConstPointer<chimera::Item> const & item) override
        {
            _inventory.insert(item);
        }

        auto size() const noexcept -> std::size_t override
        {
            return _inventory.size();
        }

        auto count(chimera::ConstPointer<chimera::Item> const & item) const noexcept -> std::size_t override
        {
            return _inventory.count(item);
        }

    private:
        chimera::FixedSizeInventory _inventory;
    };
}

TEST(InventoryTest, insert_dup)
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(
        10, "Potion", 20, "Heal some HP");

    SimpleInventory si;

    chimera::Inventory &inventory = si;
    inventory.insert(potion, 3);
    ASSERT_TRUE(inventory.contains(potion));
}
