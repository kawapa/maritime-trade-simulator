#include "Fruit.hpp"

#include <iostream>

Fruit::Fruit(size_t amount, std::string name, size_t basePrice, size_t timeToRot, size_t shelfLife)
    : Cargo(amount, name, basePrice),
      timeToRot_(timeToRot),
      shelfLife_(shelfLife) {}

Fruit::~Fruit() {}

double Fruit::getPrice() const {
    return basePrice_ * (shelfLife_ - timeToRot_);
}

size_t Fruit::getTimeToRot() const {
    return timeToRot_;
}

size_t Fruit::getShelfLife() const {
    return shelfLife_;
}

bool Fruit::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Fruit)) {
        auto fruit = static_cast<const Fruit&>(cargo);
        return (name_ == fruit.getName()) &&
               (timeToRot_ == fruit.getTimeToRot());
    }
    return false;
}

std::shared_ptr<Cargo> Fruit::clone() const {
    auto fruitClone = std::make_shared<Fruit>(
        this->getAmount(),
        this->getName(),
        this->getBasePrice(),
        this->getTimeToRot(),
        this->getShelfLife());
    return fruitClone;
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

std::ostream& operator<<(std::ostream& os, const Fruit& obj) {
    os << obj.getName() << ", amount: " << obj.getAmount() << ", price: " << obj.getPrice()
       << ", days to spoil: " << obj.getTimeToRot() << std::endl;
    return os;
}
