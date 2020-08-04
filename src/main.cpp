#include <iostream>
#include <memory>

#include "Ship.hpp"
#include "Player.hpp"
#include "Fruit.hpp"

int main() {

    auto ship1 = std::make_shared<Ship>(0, "Rainbow", 75, 50, 100);
    Player player1(ship1, 1000);

    auto fruit1 = std::make_shared<Fruit>(15, "Banan", 12, 10, 10);
    auto fruit2 = std::make_shared<Fruit>(15, "Banan", 12, 10, 10);

    ship1->load(fruit1);

    ship1->load(fruit2);

    //std::cout << fruit1->getAmount();

    auto ptr = ship1->getCargo("Banan");

    std::cout << ptr->getAmount() << std::endl;

    return 0;
}