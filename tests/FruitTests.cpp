#include <gtest/gtest.h>
#include <memory>

#include "Fruit.hpp"

struct ClassFruitTestSuite : public ::testing::Test {
    Fruit banana1{15, "Banana", 15, 10, 10};
    Fruit banana2{5, "Banana", 15, 10, 10};
    Fruit banana3{4, "Banana", 15, 9, 10};
    Fruit apple1{4, "Apple", 15, 9, 10};
};

TEST_F(ClassFruitTestSuite, operatorPlusEquals) {
    banana1 += 5;
    EXPECT_EQ(banana1.getAmount(), 20);

    banana1 += 1;
    EXPECT_EQ(banana1.getAmount(), 21);
}

TEST_F(ClassFruitTestSuite, operatorMinusEquals) {
    banana1 -= 5;
    EXPECT_EQ(banana1.getAmount(), 10);

    banana1 -= 6;
    EXPECT_EQ(banana1.getAmount(), 4);
}

TEST_F(ClassFruitTestSuite, operatorEqualsEquals) {
    EXPECT_TRUE(banana1 == banana2);
    EXPECT_FALSE(banana1 == banana3);
    EXPECT_FALSE(banana1 == apple1);
}

TEST_F(ClassFruitTestSuite, OperatorsMinusMinus) {
    banana1--;
    EXPECT_EQ(banana1.getTimeToRot(), 9);
    
    --banana3;
    EXPECT_EQ(banana3.getTimeToRot(), 8);
}
