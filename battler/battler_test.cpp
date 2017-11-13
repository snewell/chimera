#include <gtest/gtest.h>

#include <chimera/internal/make_pointer.hpp>
#include <chimera/test/jobs.hpp>
#include <chimera/test/stats.hpp>

#include <chimera/battler.hpp>

TEST(BattlerTest, ctor) // NOLINT
{
    auto fighter = chimera::test::Jobs::get(chimera::test::Jobs::Id::fighter);
    chimera::Battler bob{"Bob", fighter};

    ASSERT_EQ("Bob", bob.name());
    ASSERT_EQ(fighter, bob.job());
}

TEST(BattlerTest, ctor_stats) // NOLINT
{
    chimera::StatSource ss;
    auto strength =
        chimera::test::Stats::get(chimera::test::Stats::Id::strength);
    ss.set(strength->id(), 200);

    auto fighter = chimera::test::Jobs::get(chimera::test::Jobs::Id::fighter);
    chimera::Battler bob{"Bob", fighter, ss};

    ASSERT_EQ("Bob", bob.name());
    ASSERT_EQ(fighter, bob.job());

    auto strength_val = bob.stats().find(strength->id());
    ASSERT_TRUE(strength_val);
    ASSERT_EQ(200, *strength_val);
}

TEST(BattlerTest, set_job) // NOLINT
{
    auto fighter = chimera::test::Jobs::get(chimera::test::Jobs::Id::fighter);
    chimera::Battler bob{"Bob", fighter};

    auto mage = chimera::test::Jobs::get(chimera::test::Jobs::Id::mage);
    bob.job(mage);
    ASSERT_EQ(mage, bob.job());
}
