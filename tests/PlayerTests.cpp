#include <gtest/gtest.h>

#include "Player.hpp"
#include "Store.hpp"

#include <memory>

struct ClassPlayerTestSuite : public ::testing::Test {
    Player player;
    Store store;
};

TEST_F(ClassPlayerTestSuite, CanBuyFromTheStore) {
    store.sell(0, 10, &player);
    auto result = player.getShip()->getCargoWeight();

    EXPECT_EQ(result, 10);
}
