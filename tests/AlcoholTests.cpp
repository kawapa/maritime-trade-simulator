#include <gtest/gtest.h>

#include "Alcohol.hpp"

class ClassAlcoholTestSuite : public testing::TestWithParam<std::pair<Alcohol, Alcohol>> {
};

TEST(ClassAlcoholTestSuite, operatorEqualsEqualsReturnsFalse) {
    auto first = Alcohol{"Whisky", 40};
    auto second = Alcohol{"Wine", 12};

    EXPECT_FALSE(first == second);
}

TEST_P(ClassAlcoholTestSuite, operatorEqualsEqualsReturnsTrue) {
    auto pair = GetParam();
    
    EXPECT_TRUE(pair.first == pair.second);
}

INSTANTIATE_TEST_SUITE_P(MyInstantiationName,
                         ClassAlcoholTestSuite,
                         testing::Values(
                             std::make_pair(Alcohol{"Whisky", 40}, Alcohol{"Whisky", 40}),
                             std::make_pair(Alcohol{"Tequila", 45}, Alcohol{"Tequila", 45}),
                             std::make_pair(Alcohol{"Bourbon", 50}, Alcohol{"Bourbon", 50})
                         )
);