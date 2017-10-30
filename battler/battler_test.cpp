#include <gtest/gtest.h>

#include <chimera/internal/make_pointer.hpp>

#include <chimera/battler.hpp>

TEST(BattlerTest, ctor)
{
    auto fighter = chimera::internal::make_pointer<chimera::Job>(10, "Fighter");
    chimera::Battler bob{"Bob", fighter};

    ASSERT_EQ("Bob", bob.name());
    ASSERT_EQ(fighter, bob.job());
}

TEST(BattlerTest, set_job)
{
    auto fighter = chimera::internal::make_pointer<chimera::Job>(10, "Fighter");
    chimera::Battler bob{"Bob", fighter};

    auto mage = chimera::internal::make_pointer<chimera::Job>(20, "Mage");
    bob.job(mage);
    ASSERT_EQ(mage, bob.job());
}
