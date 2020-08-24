#include <gtest/gtest.h>

#include "Fruit.cpp"
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

TEST_F(ClassPlayerTestSuite, CanSellCargoToStore) {
    EXPECT_EQ(player.getShip()->getCargoWeight(), 0);
    player.getShip()->load(std::make_shared<Fruit>(15, "Banana", 15, 9, 10));
    EXPECT_EQ(player.getShip()->getCargoWeight(), 15);

    store.buy(0, 15, &player);

    EXPECT_EQ(player.getShip()->getCargoWeight(), 0);
    EXPECT_TRUE(player.getMoney() > 1000);
}
