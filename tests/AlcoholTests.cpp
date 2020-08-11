#include <gtest/gtest.h>

#include "Alcohol.hpp"

class ClassAlcoholTestSuite : public testing::TestWithParam<std::pair<Alcohol, Alcohol>> {
};

TEST_P(ClassAlcoholTestSuite, operatorEqualsEquals) {
    auto pair = GetParam();
    EXPECT_TRUE(pair.first == pair.second);
}

INSTANTIATE_TEST_SUITE_P(MyInstantiationName,
                         ClassAlcoholTestSuite,
                         testing::Values(
                             std::make_pair(Alcohol{1, "Whisky", 75, 40, 40}, Alcohol{5, "Whisky", 150, 40, 45}),
                             std::make_pair(Alcohol{2, "Tequila", 10, 44, 45}, Alcohol{16, "Tequila", 195, 44, 50}),
                             std::make_pair(Alcohol{3, "Bourbon", 95, 42, 40}, Alcohol{6, "Bourbon", 110, 42, 65})
                         )
);