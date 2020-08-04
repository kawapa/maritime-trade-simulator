#include <gtest/gtest.h>

#include "DryFruit.hpp"

struct ClassDryFruitTestSuite : public ::testing::Test {
    DryFruit grapes1{15, "Grapes", 15, 10, 10};
    DryFruit grapes2{5, "Grapes", 45, 10, 10};
    DryFruit grapes3{4, "Grapes", 15, 9, 10};
    DryFruit driedplums1{4, "DriedPlums", 15, 9, 10};
};

TEST_F(ClassDryFruitTestSuite, operatorEqualsEquals) {
    EXPECT_TRUE(grapes1 == grapes2);
    EXPECT_FALSE(grapes1 == grapes3);
    EXPECT_FALSE(grapes1 == driedplums1);
}

TEST_F(ClassDryFruitTestSuite, operatorMinusMinus) {
    EXPECT_TRUE(grapes1.getTimeToRot() == 10);
    for (size_t i = 0; i < 10; ++i) {
        grapes1--;
    }
    EXPECT_TRUE(grapes1.getTimeToRot() == 9);
}
