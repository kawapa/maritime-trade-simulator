#include "DryFruit.hpp"

DryFruit::DryFruit(size_t amount, std::string name, size_t basePrice, size_t timeToRot, size_t shelfLife)
    : Fruit(amount, name, basePrice, timeToRot, shelfLife) { }

DryFruit::~DryFruit() { }

double DryFruit::getPrice() const { return 3 * basePrice_; }

bool DryFruit::operator==(const Cargo& cargo) const {
    if (name_ != cargo.getName()) {
        return false;
    }
    return this->getPrice() == cargo.getPrice();
}
