#include <gtest/gtest.h>

#include <chimera/currency.hpp>

TEST(CurrencyTest, ctor)
{
    chimera::Currency gold{10, "Gold", 2.0};

    ASSERT_EQ(10, gold.id());
    ASSERT_EQ("Gold", gold.name());
    ASSERT_EQ(2.0, gold.value());
}

TEST(CurrencyTest, set_value)
{
    chimera::Currency gold{10, "Gold", 2.0};

    gold.value(3.0);
    ASSERT_EQ(3.0, gold.value());
}
