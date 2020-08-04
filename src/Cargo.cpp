#include "Cargo.hpp"

Cargo::Cargo(size_t amount, std::string name, size_t basePrice)
    : amount_(amount),
      name_(name),
      basePrice_(basePrice) { }

Cargo::~Cargo() { }

std::string Cargo::getName() const { return name_; }

size_t Cargo::getAmount() const { return amount_; }

size_t Cargo::getBasePrice() const { return basePrice_; }

Cargo& Cargo::operator+=(const size_t amount) {
    amount_ += amount;
    return *this;
}

Cargo& Cargo::operator-=(const size_t amount) {
    if (amount <= amount_) {
        amount_ -= amount;
    }
    return *this;
}
