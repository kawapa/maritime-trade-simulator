#include "Fruit.hpp"

Fruit::Fruit(size_t amount, std::string name, size_t basePrice, size_t timeToRot, size_t shelfLife)
    : Cargo(amount, name, basePrice), timeToRot_(timeToRot), shelfLife_(shelfLife) { }

Fruit::~Fruit() { }

double Fruit::getPrice() const { return basePrice_ * (shelfLife_ - timeToRot_); }
std::string Fruit::getName() const { return name_; }
size_t Fruit::getAmount() const { return amount_; }
size_t Fruit::getBasePrice() const { return basePrice_; }
size_t Fruit::getTimeToRot() const { return timeToRot_; }

Cargo& Fruit::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Fruit::operator-=(const size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    }
    return *this;
}

bool Fruit::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Fruit)) {
        auto fruit = static_cast<const Fruit&>(cargo);
        return (name_ == fruit.getName() && timeToRot_ == fruit.getTimeToRot());
    }
    return false;
}

Fruit& Fruit::operator--() {
    if (timeToRot_) {
        timeToRot_--;
    }
    return *this;
}

Fruit Fruit::operator--(int) {
    Fruit tmp(*this);
    operator--();
    return tmp;
}
