#include "Alcohol.hpp"

#include <typeinfo>

Alcohol::Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentage, size_t basePercentage)
    : Cargo(amount, name, basePrice), percentage_(percentage), basePercentage_(basePercentage) {}

Alcohol::~Alcohol() { }

double Alcohol::getPrice() const { return basePrice_ * (basePercentage_ - percentage_); }
std::string Alcohol::getName() const { return name_; }
size_t Alcohol::getAmount() const { return amount_; }
size_t Alcohol::getBasePrice() const { return basePrice_; }

size_t Alcohol::getPercentage() const { return percentage_; }

bool Alcohol::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Alcohol)) {
        const Alcohol* alcohol = static_cast<const Alcohol*>(&cargo);
        return (name_ == alcohol->getName()) && (amount_ == alcohol->getAmount()) && (basePrice_ == alcohol->getBasePrice());
    }
    return false;
}

Cargo& Alcohol::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Alcohol::operator-=(const size_t amount) {
    if (amount_ > amount) {
        amount_ -= amount;
    }
    return *this;
}