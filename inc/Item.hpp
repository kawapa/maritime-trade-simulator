#pragma once

#include "Cargo.hpp"

class Item : public Cargo {
public:
    enum class Rarity {
        common = 1,
        rare = 3,
        epic = 10,
        legendary = 25
    };

    Item(size_t, std::string, size_t, Rarity);
    ~Item() override;

    // Override from Cargo
    double getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;

private:
    const Rarity rarity_;
};
