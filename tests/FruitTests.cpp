#include <gtest/gtest.h>
#include <memory>

#include "Fruit.hpp"

struct ClassFruitTestSuite : public ::testing::Test {
    Fruit banana1{10, "Banana", 15, 10, 10};
    Fruit banana2{5, "Banana", 15, 10, 10};
    Fruit banana3{10, "Banana", 15, 9, 10};
};

TEST_F(ClassFruitTestSuite, AddingFruits) {
    banana1 += 5;
    EXPECT_TRUE(banana1.getAmount() == 15);

    banana1 += 1;
    EXPECT_TRUE(banana1.getAmount() == 16);
}

TEST_F(ClassFruitTestSuite, SubstractingFruits) {
    banana1 -= 5;
    EXPECT_TRUE(banana1.getAmount() == 5);

    banana1 -= 10;
    EXPECT_TRUE(banana1.getAmount() == 5);
}

TEST_F(ClassFruitTestSuite, ComparingFruits) {
    EXPECT_TRUE(banana1 == banana2);
    EXPECT_FALSE(banana1 == banana3);
}
