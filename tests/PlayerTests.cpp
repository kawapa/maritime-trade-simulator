#include <gtest/gtest.h>

#include "Player.hpp"
#include "Ship.hpp"

#include <memory>

struct ClassPlayerTestSuite : public ::testing::Test {
    std::shared_ptr<Ship> ship = std::make_shared<Ship>();
    Player player{ship, 1000};
};

TEST_F(ClassPlayerTestSuite, operatorPlusEquals) {
    player += 10;
    EXPECT_EQ(player.getMoney(), 1010);
    player -= 510;
    EXPECT_EQ(player.getMoney(), 500);   
}

TEST_F(ClassPlayerTestSuite, operatorMinusEquals) {
    player -= 750;
    EXPECT_EQ(player.getMoney(), 250);
    player -= 10;
    EXPECT_EQ(player.getMoney(), 240);  
}
