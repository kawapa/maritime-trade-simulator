#include "Alcohol.hpp"

#include <cmath>
#include <iostream>
#include <typeinfo>

Alcohol::Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentage, size_t basePercentage)
    : Cargo(amount, name, basePrice),
      percentage_(percentage),
      basePercentage_(basePercentage) {}

Alcohol::~Alcohol() {}

double Alcohol::getPrice() const {
    double price = basePrice_ * (percentage_ / basePercentage_);
    return std::ceil(price * 100.0) / 100.0;
}

size_t Alcohol::getPercentage() const {
    return percentage_;
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
