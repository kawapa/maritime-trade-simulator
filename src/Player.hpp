#pragma once

#include <memory>

#include "Cargo.hpp"
#include "Ship.hpp"

class Player {
public:
    Player();
    Player(std::shared_ptr<Ship> ship, size_t money);
    ~Player();

    Ship* getShip() const;
    size_t getMoney() const;
    size_t getAvailableSpace() const;
    size_t getSpeed() const;

    void buyCargo(std::shared_ptr<Cargo> cargo, size_t price);
    void sellCargo(std::shared_ptr<Cargo> cargo, size_t amount, size_t price);
    void showCargo();

    Player& operator+=(const size_t amount);
    Player& operator-=(const size_t amount);

    friend std::ostream& operator<<(std::ostream& os, const Player& obj);

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
};
