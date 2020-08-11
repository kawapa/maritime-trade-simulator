#include "Store.hpp"

#include <iostream>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

Store::Store() {
    generateNewStock();
}

Store::~Store() = default;

Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
    if (auto search = player->getCargo(cargo->getName())) {
        if (search->getAmount() < amount) {
            std::cerr << "You cannot sell more than you have!\n";
            return Response::lack_of_cargo;
        }
        search -= amount;
        player += search->getBasePrice() * amount;

        if (search->getAmount() == amount) {
            player->getShip()->removeCargoFromShip(search);
        } else {
            search -= amount;
        }
    }
    return Response::done;
}

Store::Response Store::sell(Cargo* cargo, size_t amount, Player* player) {
    if (auto search = player->getCargo(cargo->getName())) {
        if (search->getAmount() < amount) {
            std::cerr << "You cannot sell more than you have!\n";
            return Response::lack_of_cargo;
        }
        search -= amount;
        player += search->getBasePrice() * amount;

        if (search->getAmount() == amount) {
            player->getShip()->removeCargoFromShip(search);
        } else {
            search -= amount;
        }
    }
    return Response::done;
}

void Store::generateNewStock() {
}

std::ostream& operator<<(std::ostream& os, const Store& obj) {
    os << "Available cargo to buy: " << std::endl;

    for (const auto& i : obj.cargo_) {
        if (typeid(*i) == typeid(Alcohol)) {
            const Alcohol* singleCargo = static_cast<const Alcohol*>(i.get());
            os << *singleCargo;
        } else if (typeid(*i) == typeid(Fruit)) {
            const Fruit* singleCargo = static_cast<const Fruit*>(i.get());
            os << *singleCargo;
        } else if (typeid(*i) == typeid(Item)) {
            const Item* singleCargo = static_cast<const Item*>(i.get());
            os << *singleCargo;
        }
    }
    return os;
}
