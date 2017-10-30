#include <gtest/gtest.h>

#include <chimera/identified_object.hpp>

TEST(IdentifiedObjectTest, ctor) // NOLINT
{
    chimera::IdentifiedObject io{10};

    ASSERT_EQ(10, io.id());
}

TEST(IdentifiedObjectTest, set_id) // NOLINT
{
    chimera::IdentifiedObject io{10};

    io.id(20);
    ASSERT_EQ(20, io.id());
}
