#include <gtest/gtest.h>

#include <chimera/internal/make_pointer.hpp>
#include <chimera/test/currencies.hpp>

#include <chimera/money.hpp>

TEST(MoneyTest, ctor) // NOLINT
{
    auto gold =
        chimera::test::Currencies::get(chimera::test::Currencies::Id::gold);
    chimera::Money coins{gold, 10};

    ASSERT_EQ(gold, coins.currency());
    ASSERT_EQ(10, coins.amount());
    ASSERT_EQ(20, coins.value());
}

TEST(MoneyTest, set_currency) // NOLINT
{
    auto gold =
        chimera::test::Currencies::get(chimera::test::Currencies::Id::gold);
    chimera::Money coins{gold, 10};

    auto silver =
        chimera::test::Currencies::get(chimera::test::Currencies::Id::silver);
    coins.currency(silver);
    ASSERT_EQ(silver, coins.currency());
    ASSERT_EQ(15, coins.value());
}

TEST(MoneyTest, set_amount) // NOLINT
{
    auto gold =
        chimera::test::Currencies::get(chimera::test::Currencies::Id::gold);
    chimera::Money coins{gold, 10};

    coins.amount(20);
    ASSERT_EQ(20, coins.amount());
    ASSERT_EQ(40, coins.value());
}

TEST(MoneyTest, even_conversion) // NOLINT
{
    auto gold =
        chimera::test::Currencies::get(chimera::test::Currencies::Id::gold);
    chimera::Money coins{gold, 10};

    auto bronze =
        chimera::test::Currencies::get(chimera::test::Currencies::Id::bronze);
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
        chimera::test::Currencies::get(chimera::test::Currencies::Id::gold);
    chimera::Money coins{gold, 10};

    auto silver =
        chimera::test::Currencies::get(chimera::test::Currencies::Id::silver);
    auto amount = coins.convert_amount(silver);

    ASSERT_EQ(13, amount);
    auto silver_coins = coins.convert(silver);
    ASSERT_EQ(silver, silver_coins.currency());
    ASSERT_EQ(amount, silver_coins.amount());
    ASSERT_EQ(1, coins.amount());
}
