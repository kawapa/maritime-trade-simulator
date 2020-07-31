#include "Store.hpp"

#include <iostream>

Store::Store() { generateNewStock(); }
Store::~Store() { }

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (auto search = player->getCargo(cargo->getName())) {
        if (search->getAmount() < amount) {
            std::cerr << "You cannot sell more than you have!\n";
        }
        else if (search->getAmount() == amount) {
            player->getShip()->removeCargoFromShip(search);
        }
        else {
            search -= amount;
        }
    }
    else {
        std::cerr << "You can't sell it as you don't have it on the ship!\n";
    }
    return Response::done;
}

// Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
//     return Response::done;
// }

void Store::nextDay() {
    void generateNewStock();
}

void Store::generateNewStock() {
}