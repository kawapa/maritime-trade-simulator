#include "Ship.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>

#include "Cargo.hpp"

using Shipment = std::shared_ptr<Cargo>;

Ship::Ship(const std::string& name, size_t speed, size_t crew, size_t maxCrew, size_t capacity)
    : name_(name),
      speed_(speed),
      crew_(crew),
      maxCrew_(maxCrew),
      capacity_(capacity) {}

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

void Ship::setName(const std::string& name) {
    name_ = name;
}

Cargo* Ship::getCargo(std::string name) const {
    auto search = std::find_if(begin(cargo_), end(cargo_), [&name](const Shipment& c) { return name == c->getName(); });
    if (search != end(cargo_)) {
        return search->get();
    }
    return nullptr;
}

size_t Ship::getCargoWeight() const {
    size_t totalCargo = std::accumulate(begin(cargo_), end(cargo_), 0, [](size_t amounts, const Shipment& cargo) { return amounts += cargo->getAmount(); });
    return totalCargo;
}

std::vector<Shipment>::iterator Ship::returnCargoIterator(Shipment cargo) {
    return std::find_if(begin(cargo_), end(cargo_), [&cargo](const Shipment& c) { return *c == *cargo; });
}

void Ship::load(Shipment cargo) {
    if (getCargoWeight() + cargo->getAmount() <= getCapacity()) {
        auto search = std::find_if(begin(cargo_), end(cargo_), [&cargo](const Shipment& c) { return *c == *cargo; });
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
        if (search->get()->getAmount() < amount) {
            cargo_.erase(search);
        } else {
            *(search->get()) -= amount;
        }
    }
}

void Ship::removeCargoFromShip(Cargo* cargo) {
    cargo_.erase(std::find_if(begin(cargo_), end(cargo_), [cargo](Shipment c) {
        return cargo->getName() == c->getName();
    }));
}

Ship& Ship::operator+=(const size_t crew) {
    if (crew_ + crew <= maxCrew_) {
        crew_ += crew;
    } else {
        std::cerr << "Error! The number of crew members cannot be greater than " << getMaxCrew();
    }
    return *this;
}

Ship& Ship::operator-=(const size_t crew) {
    if (crew_ > crew) {
        crew_ -= crew;
    } else {
        std::cerr << "Error! The number of crew members cannot be lower than 0!";
    }
    return *this;
}
