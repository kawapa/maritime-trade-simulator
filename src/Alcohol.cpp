#include "Alcohol.hpp"

#include <cmath>
#include <iostream>
#include <typeinfo>

Alcohol::Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentage, size_t basePercentage)
    : Cargo(amount, name, basePrice),
      percentage_(percentage),
      basePercentage_(basePercentage) {}

Alcohol::Alcohol(std::string name, size_t percentage)
    : Cargo(name),
      percentage_(percentage) {}

Alcohol::~Alcohol() {}

double Alcohol::getPrice() const {
    double price = basePrice_ * (static_cast<double>(percentage_) / basePercentage_);
    return std::ceil(price * 100.0) / 100.0;
}

size_t Alcohol::getBasePercentage() const { return basePercentage_; }

size_t Alcohol::getPercentage() const {
    return percentage_;
}

std::shared_ptr<Cargo> Alcohol::clone() const {
    auto alcoholClone = std::make_shared<Alcohol>(
                this->getAmount(),
                this->getName(),
                this->getBasePrice(),
                this->getPercentage(),
                this->getBasePercentage());
    return alcoholClone;
}

bool Alcohol::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Alcohol)) {
        auto alcohol = static_cast<const Alcohol&>(cargo);
        return (name_ == alcohol.getName()) &&
               (percentage_ == alcohol.getPercentage());
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Alcohol& obj) {
    os << obj.getName() << ", amount: " << obj.getAmount() << ", price: " << obj.getPrice()
       << ", percentage of alcohol: " << obj.getPercentage() << " %" << std::endl;
    return os;
}
