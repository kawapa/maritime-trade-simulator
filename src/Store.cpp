#include "Store.hpp"

#include <algorithm>
#include <iostream>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"

Store::Store() {
    cargo_ = {
        {std::make_shared<Fruit>(15, "Banana", 15, 10, 10)},
        {std::make_shared<Fruit>(5, "Apple", 10, 10, 10)},
        {std::make_shared<Item>(1, "Sword", 75, Item::Rarity::common)}
    };
}

Store::~Store() = default;

// Store::Response Store::buy(Cargo* cargo, size_t amount, Player* player) {
//     if (auto search = player->getCargo(cargo->getName())) {
//         if (search->getAmount() < amount) {
//             std::cerr << "You cannot sell more than you have!\n";
//             return Response::lack_of_cargo;
//         }
//         search -= amount;
//         player += search->getBasePrice() * amount;

//         if (search->getAmount() == amount) {
//             player->getShip()->removeCargoFromShip(search);
//         } else {
//             search -= amount;
//         }
//     }
//     return Response::done;
// }

Cargo* Store::getCargo(size_t index) { return cargo_[index].get(); }

Store::Response Store::sell(size_t index, size_t amount, Player* player) {

    if (amount > player->getShip()->getCapacity()) {
        return Response::lack_of_cargo;
    }
    auto price = amount * cargo_[index]->getPrice();
    if (player->getMoney() < price) {
        return Response::lack_of_money;
    }
    *player -= price;

    auto newCargo = cargo_[index].get()->clone();

    if (amount == cargo_[index]->getAmount()) {
        removeFromCargo(cargo_[index]);
    }
    else {
        *cargo_[index] -= amount;
        *newCargo -= cargo_[index]->getAmount();
    }
    player->getShip()->load(std::move(newCargo));

    return Response::done;
}

std::ostream& operator<<(std::ostream& os, const Store& obj) {
    os << std::endl;
    os << "DISPLAYING WHAT'S AVAILABLE AT THE STORE:\n";
    os << std::endl;
    std::for_each(begin(obj.cargo_), end(obj.cargo_), [i = 0, &os](const std::shared_ptr<Cargo>& el) mutable {
        os << i << ") ";
        if (typeid(*el) == typeid(Alcohol)) {
            const Alcohol* singleCargo = static_cast<const Alcohol*>(el.get());
            os << *singleCargo;
        } else if (typeid(*el) == typeid(Fruit)) {
            const Fruit* singleCargo = static_cast<const Fruit*>(el.get());
            os << *singleCargo;
        } else if (typeid(*el) == typeid(Item)) {
            const Item* singleCargo = static_cast<const Item*>(el.get());
            os << *singleCargo;
        }
        ++i;
    });

    return os;
}

void Store::removeFromCargo(std::shared_ptr<Cargo> cargo) {
    auto search = std::find_if(begin(cargo_), end(cargo_), [&cargo](const std::shared_ptr<Cargo>& c) { return *c == *cargo; });
    cargo_.erase(search);
}