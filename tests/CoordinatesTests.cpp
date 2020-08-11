#include <gtest/gtest.h>

#include "Coordinates.hpp"

constexpr size_t X_1 = 10;
constexpr size_t Y_1 = 15;
constexpr size_t X_2 = 14;
constexpr size_t Y_2 = 20;


struct ClassCoordinatesTestSuite : public ::testing::Test {
    Coordinates co1{X_1, Y_1};
    Coordinates co2{X_2, Y_2};
};

TEST_F(ClassCoordinatesTestSuite, methodDistance) {
    auto expected = Coordinates::distance(co1, co2);
    ASSERT_EQ(6, expected);
    
    expected = Coordinates::distance(co1, co1);
    ASSERT_EQ(0, expected);
}

TEST_F(ClassCoordinatesTestSuite, operatorEqualsEquals) {
    Coordinates temp{X_1, Y_1};
    ASSERT_TRUE(temp == co1);
}
