#include <gtest/gtest.h>

#include "Fruit.hpp"
#include "Item.hpp"
#include "Ship.hpp"

#include <memory>

struct ClassShipTestSuite : public ::testing::Test {
    std::shared_ptr<Ship> ship = std::make_shared<Ship>(0, "Eagle", 75, 100, 50);

    std::shared_ptr<Cargo> cargo1 = std::make_shared<Fruit>(15, "Banana", 15, 10, 10);
    std::shared_ptr<Cargo> cargo2 = std::make_shared<Fruit>(15, "Banana", 15, 10, 10);
    std::shared_ptr<Cargo> cargo3 = std::make_shared<Item>(1, "Sword", 75, Item::Rarity::common);
    std::shared_ptr<Cargo> cargo4 = std::make_shared<Item>(1, "Book", 75, Item::Rarity::legendary);
};

TEST_F(ClassShipTestSuite, methodGetCargo) {
    EXPECT_EQ(nullptr, ship->getCargo("Banana"));
    ship->load(cargo1);
    EXPECT_TRUE(ship->getCargo("Banana"));
}

TEST_F(ClassShipTestSuite, methodGetCargoWeight) {
    EXPECT_EQ(0, ship->getCargoWeight());
    ship->load(cargo1);
    EXPECT_EQ(15, ship->getCargoWeight());
    ship->load(cargo2);
    ship->load(cargo3);
    EXPECT_EQ(31, ship->getCargoWeight());
}

TEST_F(ClassShipTestSuite, methodLoad) {
    ship->load(cargo1);
    auto search = ship->getCargo("Banana");
    EXPECT_TRUE(search);
    EXPECT_EQ(15, search->getAmount());
    ship->load(cargo2);
    EXPECT_EQ(30, search->getAmount());
}

TEST_F(ClassShipTestSuite, methodUnload) {
    EXPECT_EQ(0, ship->getCargoWeight());
    ship->load(cargo1);
    EXPECT_EQ(15, ship->getCargoWeight());
    ship->unload(cargo1, 14);
    EXPECT_EQ(1, ship->getCargoWeight());
}

TEST_F(ClassShipTestSuite, methodRemoveCargoFromShip) {

}

TEST_F(ClassShipTestSuite, operatorPlusEquals) {

}

TEST_F(ClassShipTestSuite, operatorMinusEquals) {

}