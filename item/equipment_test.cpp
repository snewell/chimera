#include <gtest/gtest.h>

#include <chimera/equipment.hpp>

TEST(EquipmentTest, ctor) // NOLINT
{
    chimera::Equipment sword{10, "Sword", 100, "Beginner's weapon"};
    ASSERT_EQ(0, sword.stats().count());
}

TEST(EquipmentTest, const_stats) // NOLINT
{
    chimera::Equipment sword{10, "Sword", 100, "Beginner's weapon"};
    ASSERT_EQ(0, const_cast<chimera::Equipment&>(sword).stats().count());

    sword.stats().set(10, 100);
    ASSERT_EQ(1, const_cast<chimera::Equipment&>(sword).stats().count());
}
