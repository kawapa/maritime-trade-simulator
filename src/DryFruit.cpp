#include "DryFruit.hpp"

DryFruit::DryFruit(size_t amount, std::string name, size_t basePrice, size_t timeToRot, size_t shelfLife)
    : Fruit(amount, name, basePrice, timeToRot, shelfLife) { }

DryFruit::~DryFruit() { }

double DryFruit::getPrice() const { return 3 * basePrice_; }

Fruit& DryFruit::operator--() {
    static size_t counter = 0;
    counter--;
    if (counter % 10 == 0 && timeToRot_) {
        timeToRot_--;
    }
    return *this;
}

Fruit DryFruit::operator--(int) {
    DryFruit tmp(*this);
    operator--();
    return tmp;
}

bool DryFruit::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(DryFruit)) {
        auto fruit = static_cast<const DryFruit&>(cargo);
        return (name_ == fruit.getName() && timeToRot_ == fruit.getTimeToRot());
    }
    return false;
}
