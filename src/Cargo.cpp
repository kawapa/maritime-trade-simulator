#include "Cargo.hpp"

Cargo::Cargo(size_t amount, std::string name, size_t basePrice)
    : amount_(amount), name_(name), basePrice_(basePrice) { }

Cargo::~Cargo() { }
