#include <gtest/gtest.h>

#include <chimera/stat.hpp>

TEST(StatSourceTest, ctor) // NOLINT
{
    chimera::StatSource ss;
    ASSERT_EQ(0, ss.count());
}

TEST(StatSourceTest, find_nothing) // NOLINT
{
    chimera::StatSource ss;
    auto strength = ss.find(10);
    ASSERT_FALSE(strength);
}

TEST(StatSourceTest, set_missing) // NOLINT
{
    chimera::StatSource ss;
    ss.set(10, 100);

    auto strength = ss.find(10);
    ASSERT_TRUE(strength);
    ASSERT_EQ(100, *strength);
}

TEST(StatSourceTest, set_present) // NOLINT
{
    chimera::StatSource ss;
    ss.set(10, 100);
    ss.set(10, 500);

    auto strength = ss.find(10);
    ASSERT_TRUE(strength);
    ASSERT_EQ(500, *strength);
}

TEST(StatSourceTest, adjust_missing) // NOLINT
{
    chimera::StatSource ss;
    ss.adjust(10, 100);

    auto strength = ss.find(10);
    ASSERT_TRUE(strength);
    ASSERT_EQ(100, *strength);
}

TEST(StatSourceTest, adjust_present) // NOLINT
{
    chimera::StatSource ss;
    ss.adjust(10, 100);
    ss.adjust(10, 500);

    auto strength = ss.find(10);
    ASSERT_TRUE(strength);
    ASSERT_EQ(600, *strength);
}

TEST(StatSourceTest, remove_present) // NOLINT
{
    chimera::StatSource ss;

    ss.set(10, 10);
    ss.remove(10);
    ASSERT_EQ(0, ss.count());
}

TEST(StatSourceTest, remove_missing) // NOLINT
{
    chimera::StatSource ss;

    ss.remove(10);
    ASSERT_EQ(0, ss.count());
}
