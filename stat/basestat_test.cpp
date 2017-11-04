#include <gtest/gtest.h>

#include <chimera/stat.hpp>

TEST(BaseStatTest, ctor)
{
    chimera::BaseStat strength{10, "Strength", 0};

    ASSERT_EQ(10, strength.id());
    ASSERT_EQ("Strength", strength.name());
    ASSERT_EQ(0, strength.fallback());
}

TEST(BaseStatTest, set_fallback)
{
    chimera::BaseStat strength{10, "Strength", 0};

    strength.fallback(100);
    ASSERT_EQ(100, strength.fallback());
}

TEST(BaseStatTest, get_set_value)
{
    chimera::BaseStat strength{10, "Strength", 0};
    chimera::StatSource stats;

    stats.set(strength.id(), 100);
    ASSERT_EQ(100, strength.get(stats));
}

TEST(BaseStatTest, get_unset_value)
{
    chimera::BaseStat strength{10, "Strength", 0};
    chimera::StatSource stats;

    ASSERT_EQ(0, strength.get(stats));
}
