#include <gtest/gtest.h>

#include <chimera/stat.hpp>

TEST(ComplexStatTest, ctor)
{
    auto fn = [](auto const & stats) {
        (void)stats;
        return 0;
    };
    chimera::ComplexStat strength{10, "Strength", fn};
    chimera::StatSource stats;

    ASSERT_EQ(10, strength.id());
    ASSERT_EQ("Strength", strength.name());
    ASSERT_EQ(0, strength.calculation()(stats));
}

TEST(ComplexStatTest, set_calculation)
{
    auto fn = [](auto const & stats) {
        (void)stats;
        return 0;
    };
    chimera::ComplexStat strength{10, "Strength", fn};

    auto fn2 = [](auto const & stats) {
        (void)stats;
        return 100;
    };

    chimera::StatSource stats;
    strength.calculation(fn2);
    ASSERT_EQ(100, strength.calculation()(stats));
}

TEST(ComplexStatTest, get_value)
{
    auto fn = [](auto const & stats) {
        (void)stats;
        return 10;
    };
    chimera::ComplexStat strength{10, "Strength", fn};
    chimera::StatSource stats;

    stats.set(strength.id(), 100);
    ASSERT_EQ(10, strength.get(stats));
}
