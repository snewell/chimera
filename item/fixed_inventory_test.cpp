#include <gtest/gtest.h>

#include <chimera/inventory.hpp>
#include <chimera/internal/make_pointer.hpp>

TEST(FixedInventoryTest, ctor)
{
    chimera::FixedSizeInventory fi{10};

    ASSERT_EQ(0, fi.size());
}

TEST(FixedInventoryTest, insert_success)
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(10, "Potion", 20, "Heal some HP");

    chimera::FixedSizeInventory fi{10};
    fi.insert(potion);
    ASSERT_EQ(1, fi.size());
    ASSERT_TRUE(fi.contains(potion));
    ASSERT_EQ(1, fi.count(potion));
}

TEST(FixedInventoryTest, insert_dup_success)
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(10, "Potion", 20, "Heal some HP");

    chimera::FixedSizeInventory fi{10};
    fi.insert(potion, 3);
    ASSERT_EQ(3, fi.size());
    ASSERT_TRUE(fi.contains(potion));
    ASSERT_EQ(3, fi.count(potion));
}

TEST(FixedInventoryTest, insert_full)
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(10, "Potion", 20, "Heal some HP");

    chimera::FixedSizeInventory fi{0};
    fi.insert(potion);
    ASSERT_EQ(0, fi.size());
    ASSERT_FALSE(fi.contains(potion));
}

TEST(FixedInventoryTest, insert_overflow)
{
    auto potion = chimera::internal::make_pointer<chimera::Item>(10, "Potion", 20, "Heal some HP");

    chimera::FixedSizeInventory fi{5};
    fi.insert(potion, 6);
    ASSERT_EQ(0, fi.size());
    ASSERT_FALSE(fi.contains(potion));
}
