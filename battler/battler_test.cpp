#include <gtest/gtest.h>

#include <chimera/internal/make_pointer.hpp>
#include <chimera/test/jobs.hpp>

#include <chimera/battler.hpp>

TEST(BattlerTest, ctor) // NOLINT
{
    auto fighter = chimera::test::Jobs::get(chimera::test::Jobs::Id::fighter);
    chimera::Battler bob{"Bob", fighter};

    ASSERT_EQ("Bob", bob.name());
    ASSERT_EQ(fighter, bob.job());
}

TEST(BattlerTest, set_job) // NOLINT
{
    auto fighter = chimera::test::Jobs::get(chimera::test::Jobs::Id::fighter);
    chimera::Battler bob{"Bob", fighter};

    auto mage = chimera::test::Jobs::get(chimera::test::Jobs::Id::mage);
    bob.job(mage);
    ASSERT_EQ(mage, bob.job());
}
