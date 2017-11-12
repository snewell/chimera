#include <gtest/gtest.h>

#include <chimera/internal/make_pointer.hpp>
#include <chimera/inventory.hpp>

TEST(StackedInventoryTest, ctor) // NOLINT
{
    chimera::StackedInventory si{10, 10};

    ASSERT_EQ(0, si.size());
}

TEST(StackedInventoryTest, insert_success) // NOLINT
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(
        10, "Potion", 20, "Heal some HP");

    chimera::StackedInventory si{10, 10};
    si.insert(potion);
    ASSERT_EQ(1, si.size());
    ASSERT_TRUE(si.contains(potion));
    ASSERT_EQ(1, si.count(potion));
}

TEST(StackedInventoryTest, insert_dup_success) // NOLINT
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(
        10, "Potion", 20, "Heal some HP");

    chimera::StackedInventory si{10, 10};
    si.insert(potion, 3);
    ASSERT_EQ(3, si.size());
    ASSERT_TRUE(si.contains(potion));
    ASSERT_EQ(3, si.count(potion));
}

TEST(StackedInventoryTest, insert_existing) // NOLINT
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(
        10, "Potion", 20, "Heal some HP");

    chimera::StackedInventory si{10, 10};
    si.insert(potion);
    si.insert(potion);
    ASSERT_EQ(2, si.count(potion));
}

TEST(StackedInventoryTest, insert_full) // NOLINT
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(
        10, "Potion", 20, "Heal some HP");

    chimera::StackedInventory si{0, 10};
    ASSERT_THROW(si.insert(potion),
                 chimera::Inventory::InsufficentSpaceException);
    ASSERT_EQ(0, si.size());
    ASSERT_FALSE(si.contains(potion));
    ASSERT_EQ(0, si.count(potion));
}

TEST(StackedInventoryTest, insert_overflow) // NOLINT
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(
        10, "Potion", 20, "Heal some HP");

    chimera::StackedInventory si{5, 5};
    si.insert(potion);
    auto insert_fn = [&si, potion]() { si.insert(potion, 5); };
    ASSERT_THROW(insert_fn(), chimera::Inventory::InsufficentSpaceException);
    ASSERT_EQ(1, si.size());
}

TEST(StackedInventoryTest, insert_new_overflow) // NOLINT
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(
        10, "Potion", 20, "Heal some HP");

    chimera::StackedInventory si{5, 5};
    auto insert_fn = [&si, potion]() { si.insert(potion, 6); };
    ASSERT_THROW(insert_fn(), chimera::Inventory::InsufficentSpaceException);
    ASSERT_EQ(0, si.size());
    ASSERT_FALSE(si.contains(potion));
}
