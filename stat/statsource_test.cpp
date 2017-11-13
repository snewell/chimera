#include <gtest/gtest.h>

#include <chimera/test/stats.hpp>
#include <chimera/stat.hpp>

TEST(StatSourceTest, ctor) // NOLINT
{
    chimera::StatSource ss;
    ASSERT_EQ(0, ss.count());
}

TEST(StatSourceTest, find_nothing) // NOLINT
{
    chimera::StatSource ss;
    auto strength = chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    auto val = ss.find(strength->id());
    ASSERT_FALSE(val);
}

TEST(StatSourceTest, set_missing) // NOLINT
{
    chimera::StatSource ss;
    ss.set(10, 100);

    auto strength = chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    auto val = ss.find(strength->id());
    ASSERT_TRUE(val);
    ASSERT_EQ(100, *val);
}

TEST(StatSourceTest, set_present) // NOLINT
{
    chimera::StatSource ss;
    auto strength = chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    ss.set(strength->id(), 100);
    ss.set(strength->id(), 500);

    auto val = ss.find(strength->id());
    ASSERT_TRUE(val);
    ASSERT_EQ(500, *val);
}

TEST(StatSourceTest, adjust_missing) // NOLINT
{
    chimera::StatSource ss;
    auto strength = chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    ss.adjust(strength->id(), 100);

    auto val = ss.find(strength->id());
    ASSERT_TRUE(val);
    ASSERT_EQ(100, *val);
}

TEST(StatSourceTest, adjust_present) // NOLINT
{
    chimera::StatSource ss;
    auto strength = chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    ss.adjust(strength->id(), 100);
    ss.adjust(strength->id(), 500);

    auto val = ss.find(strength->id());
    ASSERT_TRUE(val);
    ASSERT_EQ(600, *val);
}

TEST(StatSourceTest, remove_present) // NOLINT
{
    chimera::StatSource ss;

    auto strength = chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    ss.set(strength->id(), 10);
    ss.remove(strength->id());
    ASSERT_EQ(0, ss.count());
}

TEST(StatSourceTest, remove_missing) // NOLINT
{
    chimera::StatSource ss;

    auto strength = chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    ss.remove(strength->id());
    ASSERT_EQ(0, ss.count());
}
