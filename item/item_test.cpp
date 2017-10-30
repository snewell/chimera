#include <gtest/gtest.h>

#include <chimera/item.hpp>

TEST(ItemTest, ctor) // NOLINT
{
    chimera::Item potion{10, "Potion", 20, "Heal some HP"};

    ASSERT_EQ(10, potion.id());
    ASSERT_EQ("Potion", potion.name());
    ASSERT_EQ(20, potion.value());
    ASSERT_EQ("Heal some HP", potion.description());
}

TEST(ItemTest, set_value) // NOLINT
{
    chimera::Item potion{10, "Potion", 20, "Heal some HP"};

    potion.value(100);
    ASSERT_EQ(100, potion.value());
}

TEST(ItemTest, set_description) // NOLINT
{
    chimera::Item potion{10, "Potion", 20, "Heal some HP"};

    potion.description("Recover HP");
    ASSERT_EQ("Recover HP", potion.description());
}
