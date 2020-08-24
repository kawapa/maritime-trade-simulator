#include "Ship.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>

#include "Alcohol.hpp"
#include "Fruit.hpp"
#include "Item.hpp"
#include "Cargo.hpp"

using Shipment = std::shared_ptr<Cargo>;

Ship::Ship() : Ship("Eagle", 5, 10, 30, 50) {}

Ship::Ship(const std::string& name, size_t speed, size_t crew, size_t maxCrew, size_t capacity)
    : name_(name),
      speed_(speed),
      crew_(crew),
      maxCrew_(maxCrew),
      capacity_(capacity)
{}

Ship::~Ship() = default;

std::string Ship::getName() const {
    return name_;
}

size_t Ship::getSpeed() const {
    return speed_;
}

size_t Ship::getMaxCrew() const {
    return maxCrew_;
}

size_t Ship::getCapacity() const {
    return capacity_;
}

size_t Ship::getCrew() const {
    return crew_;
}

size_t Ship::getCargoWeight() const {
    size_t totalCargo = std::accumulate(begin(cargo_), end(cargo_), 0, [](size_t amounts, const Shipment& cargo) {
        return amounts += cargo->getAmount(); });
    return totalCargo;
}

Cargo* Ship::getCargo(size_t index) { return cargo_[index].get(); }

std::vector<Shipment>::iterator Ship::returnCargoIterator(Shipment cargo) {
    return std::find_if(begin(cargo_), end(cargo_), [&cargo](const Shipment& c) { return *c == *cargo; });
}

void Ship::load(Shipment cargo) {
    if (getCargoWeight() + cargo->getAmount() <= getCapacity()) {
        auto search = returnCargoIterator(cargo);
        if (search != end(cargo_)) {
            *(search->get()) += cargo->getAmount();
        } else {
            cargo_.push_back(cargo);
        }
    }
}

void Ship::unload(Shipment cargo, size_t amount) {
    auto search = returnCargoIterator(cargo);
    if (search != end(cargo_)) {
        if (search->get()->getAmount() == amount) {
            cargo_.erase(search);
        } else {
            *(search->get()) -= amount;
        }
    }
}

void Ship::printCargo() const {
    std::cout << std::endl;
    std::cout << "DISPLAYING [[ YOUR ]] CARGO:\n";
    std::cout << std::endl;
    std::for_each(begin(cargo_), end(cargo_), [i = 0](const std::shared_ptr<Cargo>& el) mutable {
        std::cout << i << ") ";
        if (typeid(*el) == typeid(Alcohol)) {
            const Alcohol* singleCargo = static_cast<const Alcohol*>(el.get());
            std::cout << *singleCargo;
        } else if (typeid(*el) == typeid(Fruit)) {
            const Fruit* singleCargo = static_cast<const Fruit*>(el.get());
            std::cout << *singleCargo;
        } else if (typeid(*el) == typeid(Item)) {
            const Item* singleCargo = static_cast<const Item*>(el.get());
            std::cout << *singleCargo;
        }
        ++i;
    });
}
