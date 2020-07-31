#include "Item.hpp"

Item::Item(size_t amount, std::string name, size_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice), rarity_(rarity) { }

Item::~Item() { }

double Item::getPrice() const { return basePrice_ * static_cast<int>(rarity_); }

std::string Item::getName() const { return name_; }

size_t Item::getAmount() const { return amount_; }

size_t Item::getBasePrice() const { return basePrice_; }
