#include <gtest/gtest.h>

#include <chimera/internal/make_pointer.hpp>
#include <chimera/inventory.hpp>
#include <chimera/test/items.hpp>

TEST(FixedInventoryTest, ctor) // NOLINT
{
    chimera::FixedSizeInventory fi{10};

    ASSERT_EQ(0, fi.size());
}

TEST(FixedInventoryTest, insert_success) // NOLINT
{
    auto potion = chimera::test::Items::get(chimera::test::Items::Id::potion);
    chimera::FixedSizeInventory fi{10};
    fi.insert(potion);
    ASSERT_EQ(1, fi.size());
    ASSERT_TRUE(fi.contains(potion));
    ASSERT_EQ(1, fi.count(potion));
}

TEST(FixedInventoryTest, insert_dup_success) // NOLINT
{
    auto potion = chimera::test::Items::get(chimera::test::Items::Id::potion);
    chimera::FixedSizeInventory fi{10};
    fi.insert(potion, 3);
    ASSERT_EQ(3, fi.size());
    ASSERT_TRUE(fi.contains(potion));
    ASSERT_EQ(3, fi.count(potion));
}

TEST(FixedInventoryTest, insert_full) // NOLINT
{
    auto potion = chimera::test::Items::get(chimera::test::Items::Id::potion);
    chimera::FixedSizeInventory fi{0};
    ASSERT_THROW(fi.insert(potion),
                 chimera::Inventory::InsufficentSpaceException);
    ASSERT_EQ(0, fi.size());
    ASSERT_FALSE(fi.contains(potion));
}

TEST(FixedInventoryTest, insert_overflow) // NOLINT
{
    auto potion = chimera::test::Items::get(chimera::test::Items::Id::potion);
    chimera::FixedSizeInventory fi{5};
    auto const insert_fn = [&fi, potion]() { fi.insert(potion, 6); };
    ASSERT_THROW(insert_fn(), chimera::Inventory::InsufficentSpaceException);
    ASSERT_EQ(0, fi.size());
    ASSERT_FALSE(fi.contains(potion));
}
