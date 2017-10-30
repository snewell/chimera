#include <gtest/gtest.h>

#include <chimera/job.hpp>

TEST(JobTest, ctor)
{
    chimera::Job fighter{10, "Fighter"};

    ASSERT_EQ(10, fighter.id());
    ASSERT_EQ("Fighter", fighter.name());
}
