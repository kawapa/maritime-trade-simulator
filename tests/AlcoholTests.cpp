#include <gtest/gtest.h>

#include "Alcohol.hpp"

struct ClassAlcoholTestSuite : public ::testing::Test {
    Alcohol alcohol1{5, "Whisky", 75, 40, 40};
    Alcohol alcohol2{5, "Whisky", 150, 40, 45};
    Alcohol alcohol3{5, "Whisky", 75, 39, 40};
};

TEST_F(ClassAlcoholTestSuite, operatorEqualsEquals) {
    EXPECT_TRUE(alcohol1 == alcohol2);
    EXPECT_FALSE(alcohol1 == alcohol3);
}
