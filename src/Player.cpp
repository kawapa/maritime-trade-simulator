#include "Player.hpp"

#include "Fruit.hpp"
#include "Item.hpp"
#include "Alcohol.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

Player::Player() : Player(std::make_shared<Ship>(), 1000) {}

Player::Player(std::shared_ptr<Ship> ship, size_t money)
    : ship_(ship),
      money_(money) {}

Player::~Player() = default;

Ship* Player::getShip() const {
    return ship_.get();
}

size_t Player::getMoney() const {
    return money_;
}

size_t Player::getAvailableSpace() const {
    return getShip()->getCapacity() - getShip()->getCargoWeight();
}

size_t Player::getSpeed() const {
    return ship_->getSpeed();
}

Player& Player::operator+=(const size_t amount) {
    money_ += amount;
    return *this;
}

Player& Player::operator-=(const size_t amount) {
    if (money_ > amount) {
        money_ -= amount;
    }
    return *this;
}

void Player::showCargo() { getShip()->printCargo(); }

void Player::buyCargo(std::shared_ptr<Cargo> cargo, size_t price) {
    money_ -= price;
    getShip()->load(cargo);
}

void Player::sellCargo(std::shared_ptr<Cargo> cargo, size_t amount, size_t price) {
    money_ += price;
    getShip()->unload(cargo, amount);
}