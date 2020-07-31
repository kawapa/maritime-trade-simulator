#include "Player.hpp"

#include <algorithm>

Player::Player(std::shared_ptr<Ship> ship, size_t money)
    : ship_(ship), money_(money) { }

Ship* Player::getShip() const { return ship_.get(); }

size_t Player::getMoney() const { return money_; }

size_t Player::getAvailableSpace() const { return getShip()->getCapacity() - getShip()->getCargoWeight(); }

size_t Player::getSpeed() const { return ship_->getSpeed(); }

Cargo* Player::getCargo(std::string name) const { return getShip()->getCargo(name); }

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
