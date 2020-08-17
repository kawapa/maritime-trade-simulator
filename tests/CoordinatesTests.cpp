#include <gtest/gtest.h>

#include "Coordinates.hpp"

#include <tuple>

struct ClassCoordinatesTestSuite : public testing::TestWithParam<std::tuple<Coordinates, Coordinates, bool, int>> {
};

TEST_P(ClassCoordinatesTestSuite, methodDistance) {
    auto [first, second, equal, expectedDistance] = GetParam();
    auto distance = Coordinates::distance(first, second);
    
    EXPECT_EQ(distance, expectedDistance);
}

TEST_P(ClassCoordinatesTestSuite, operatorEqualsEquals) {
    auto [first, second, equal, expectedDistance] = GetParam();
    
    EXPECT_EQ(first == second, equal);
}

INSTANTIATE_TEST_SUITE_P(MyInstantiationName,
                         ClassCoordinatesTestSuite,
                         testing::Values(
                             std::make_tuple(Coordinates{0, 5}, Coordinates{0, 5}, true, 0),
                             std::make_tuple(Coordinates{1, 6}, Coordinates{4, 10}, false, 7),
                             std::make_tuple(Coordinates{4, 10}, Coordinates{0, 0}, false, 14),
                             std::make_tuple(Coordinates{10, 10}, Coordinates{2, 5}, false, 13)
                         )
);