#include "Item.hpp"

Item::Item(size_t amount, std::string name, size_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice),
      rarity_(rarity) { }

Item::~Item() { }

Item::Rarity Item::getRarity() const { return rarity_; }

double Item::getPrice() const { return basePrice_ * static_cast<int>(rarity_); }

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Item)) {
        auto item = static_cast<const Item&>(cargo);
        return (name_ == item.getName() &&
           basePrice_ == item.getBasePrice() &&
           rarity_ == item.getRarity());
    }
    return false;
}
