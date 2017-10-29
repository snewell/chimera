#include <gtest/gtest.h>

#include <chimera/named_object.hpp>

TEST(NamedObjectTest, ctor)
{
    chimera::NamedObject no{"Teacup"};

    ASSERT_EQ("Teacup", no.name());
}

TEST(NamedObjectTest, set_name)
{
    chimera::NamedObject no{"Teacup"};

    no.name("Whiskers");
    ASSERT_EQ("Whiskers", no.name());
}
