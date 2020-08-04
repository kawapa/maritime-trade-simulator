#include <gtest/gtest.h>

#include "Item.hpp"

struct ClassItemTestSuite : public ::testing::Test {
    Item item1{1, "Sword", 75, Item::Rarity::common};
    Item item2{1, "Sword", 75, Item::Rarity::common};
    Item item3{1, "Sword", 150, Item::Rarity::rare};
    Item item4{1, "Book", 75, Item::Rarity::common};
};

TEST_F(ClassItemTestSuite, operatorEqualsEquals) {
    EXPECT_TRUE(item1 == item2);
    EXPECT_FALSE(item1 == item3);
    EXPECT_FALSE(item1 == item4);
}

TEST_F(ClassItemTestSuite, operatorPlusEquals) {
    item1 += item2.getAmount();
    EXPECT_TRUE(item1.getAmount() == 2);
}
