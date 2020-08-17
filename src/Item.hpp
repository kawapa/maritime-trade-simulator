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

    Rarity getRarity() const;

    // Override from Cargo
    double getPrice() const override;
    virtual std::shared_ptr<Cargo> clone() const;

    // Override from Cargo
    bool operator==(const Cargo& cargo) const override;

    friend std::ostream& operator<<(std::ostream& os, const Item& obj);

private:
    const Rarity rarity_;
};
