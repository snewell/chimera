#include <gtest/gtest.h>

#include <chimera/internal/make_pointer.hpp>

#include <chimera/money.hpp>

TEST(MoneyTest, ctor) // NOLINT
{
    auto gold =
        chimera::internal::make_pointer<chimera::Currency>(10, "Gold", 2.0);
    chimera::Money coins{gold, 10};

    ASSERT_EQ(gold, coins.currency());
    ASSERT_EQ(10, coins.amount());
    ASSERT_EQ(20, coins.value());
}

TEST(MoneyTest, set_currency) // NOLINT
{
    auto gold =
        chimera::internal::make_pointer<chimera::Currency>(10, "Gold", 2.0);
    chimera::Money coins{gold, 10};

    auto silver =
        chimera::internal::make_pointer<chimera::Currency>(20, "Silver", 1.5);
    coins.currency(silver);
    ASSERT_EQ(silver, coins.currency());
    ASSERT_EQ(15, coins.value());
}

TEST(MoneyTest, set_amount) // NOLINT
{
    auto gold =
        chimera::internal::make_pointer<chimera::Currency>(10, "Gold", 2.0);
    chimera::Money coins{gold, 10};

    coins.amount(20);
    ASSERT_EQ(20, coins.amount());
    ASSERT_EQ(40, coins.value());
}

TEST(MoneyTest, even_conversion) // NOLINT
{
    auto gold =
        chimera::internal::make_pointer<chimera::Currency>(10, "Gold", 2.0);
    chimera::Money coins{gold, 10};

    auto bronze =
        chimera::internal::make_pointer<chimera::Currency>(20, "Bronze", 1.0);
    auto amount = coins.convert_amount(bronze);

    ASSERT_EQ(20, amount);
    auto bronze_coins = coins.convert(bronze);
    ASSERT_EQ(bronze, bronze_coins.currency());
    ASSERT_EQ(amount, bronze_coins.amount());
    ASSERT_EQ(0, coins.amount());
}

TEST(MoneyTest, uneven_conversion) // NOLINT
{
    auto gold =
        chimera::internal::make_pointer<chimera::Currency>(10, "Gold", 2.0);
    chimera::Money coins{gold, 10};

    auto silver =
        chimera::internal::make_pointer<chimera::Currency>(20, "Silver", 1.5);
    auto amount = coins.convert_amount(silver);

    ASSERT_EQ(13, amount);
    auto silver_coins = coins.convert(silver);
    ASSERT_EQ(silver, silver_coins.currency());
    ASSERT_EQ(amount, silver_coins.amount());
    ASSERT_EQ(1, coins.amount());
}
