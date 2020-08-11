#include <gtest/gtest.h>

#include "Fruit.hpp"
#include "Item.hpp"
#include "Ship.hpp"

#include <memory>

const std::string NAME = "Eagle";
constexpr size_t SPEED = 4;
constexpr size_t CREW = 10;
constexpr size_t MAX_CREW = 30;
constexpr size_t CAPACITY = 50;

const std::string FRUIT_NAME = "Banana";
const std::string ITEM_NAME1 = "Sword";
const std::string ITEM_NAME2 = "Book";
constexpr size_t ITEM_PRICE

struct ClassShipTestSuite : public ::testing::Test {
    Ship ship{NAME, SPEED, CREW, MAX_CREW, CAPACITY};
    
    std::shared_ptr<Fruit> cargo1{new Fruit(15, "Banana", 15, 10, 10)};
    std::shared_ptr<Fruit> cargo2{new Fruit(15, "Banana", 15, 10, 10)};
    std::shared_ptr<Item> cargo3{new Item(1, ITEM_NAME1, 75, Item::Rarity::common)};
    std::shared_ptr<Item> cargo4{new Item(1, ITEM_NAME2, 75, Item::Rarity::legendary)};  
};

TEST_F(ClassShipTestSuite, methodGetCargoWeight) {
    EXPECT_EQ(0, ship.getCargoWeight());

    ship.load(cargo1);
    EXPECT_EQ(15, ship.getCargoWeight());

    ship.load(cargo2);
    ship.load(cargo3);
    EXPECT_EQ(31, ship.getCargoWeight());
}

TEST_F(ClassShipTestSuite, methodLoad) {
    ship.load(cargo1);
    auto search = ship.getCargo("Banana");
    EXPECT_TRUE(search);
    EXPECT_EQ(15, search->getAmount());

    ship.load(cargo2);
    EXPECT_EQ(30, search->getAmount());
}

TEST_F(ClassShipTestSuite, methodUnload) {
    EXPECT_EQ(0, ship.getCargoWeight());

    ship.load(cargo1);
    EXPECT_EQ(15, ship.getCargoWeight());

    ship.unload(cargo1, 14);
    EXPECT_EQ(1, ship.getCargoWeight());
}

TEST_F(ClassShipTestSuite, operatorPlusEquals) {
    EXPECT_EQ(10, ship.getCrew());

    ship += 10;
    EXPECT_EQ(20, ship.getCrew());
}

TEST_F(ClassShipTestSuite, operatorMinusEquals) {
    EXPECT_EQ(10, ship.getCrew());

    ship += 10;
    ship -= 6;
    EXPECT_EQ(14, ship.getCrew());
}
