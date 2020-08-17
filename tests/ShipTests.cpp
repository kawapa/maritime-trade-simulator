#include <gtest/gtest.h>

#include "Fruit.hpp"
#include "Item.hpp"
#include "Ship.hpp"

#include <memory>

struct ClassShipTestSuite : public ::testing::Test {
    Ship ship;

    std::shared_ptr<Fruit> fruit1 = std::make_shared<Fruit>(15, "Banana", 15, 10, 10);
    std::shared_ptr<Fruit> fruit2 = std::make_shared<Fruit>(5, "Banana", 5, 10, 10);
    std::shared_ptr<Fruit> fruit3 = std::make_shared<Fruit>(2, "Apple", 5, 8, 10);
    std::shared_ptr<Item> item1 = std::make_shared<Item>(1, "Book", 75, Item::Rarity::common);
    std::shared_ptr<Item> item2 = std::make_shared<Item>(51, "Sword", 30, Item::Rarity::legendary);
};

TEST_F(ClassShipTestSuite, emptyShipShouldReturnCargoWeightZero) {
    // GIVEN

    // WHEN
    auto result = ship.getCargoWeight();

    // THEN
    ASSERT_EQ(result, 0);
}

TEST_F(ClassShipTestSuite, nonEmptyShipShouldReturnCargoWeight) {
    ship.load(std::make_shared<Fruit>(15, "Banana", 15, 10, 10));

    EXPECT_EQ(ship.getCargoWeight(), 15);
}

TEST_F(ClassShipTestSuite, afterShoppingAndSellingShipShouldReturnCargoWeight) {
    ship.load(fruit1);
    ship.load(fruit2);
    ship.unload(std::make_shared<Fruit>(12, "Banana", 10, 10, 10), 12);
    ship.load(item1);

    EXPECT_EQ(ship.getCargoWeight(), 9);
}

TEST_F(ClassShipTestSuite, shipShouldNotAcceptBiggerLoadThanCapacity) {
    ship.load(item2);

    EXPECT_EQ(ship.getCargoWeight(), 0);
}