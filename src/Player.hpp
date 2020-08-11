#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Player {
public:
    Player(std::shared_ptr<Ship> ship, size_t money);
    ~Player();

    Ship* getShip() const;
    size_t getMoney() const;
    size_t getAvailableSpace() const;
    size_t getSpeed() const;
    Cargo* getCargo(std::string name) const;

    Player& operator+=(const size_t amount);
    Player& operator-=(const size_t amount);

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
};
