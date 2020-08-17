#include "Item.hpp"

#include <iostream>

Item::Item(size_t amount, std::string name, size_t basePrice, Rarity rarity)
    : Cargo(amount, name, basePrice),
      rarity_(rarity) { }

Item::~Item() { }

Item::Rarity Item::getRarity() const { return rarity_; }

double Item::getPrice() const { return basePrice_ * static_cast<int>(rarity_); }

bool Item::operator==(const Cargo& cargo) const {
    if (typeid(cargo) == typeid(Item)) {
        auto item = static_cast<const Item&>(cargo);
        return name_ == item.getName() &&
               rarity_ == item.getRarity();
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Item& obj) {
        os << obj.getName() << ", amount: " << obj.getAmount() << ", price: " << obj.getPrice() << std::endl;
        return os;
}

std::shared_ptr<Cargo> Item::clone() const {
    auto itemClone = std::make_shared<Item>(
        this->getAmount(),
        this->getName(),
        this->getBasePrice(),
        this->getRarity());
    return itemClone;
}