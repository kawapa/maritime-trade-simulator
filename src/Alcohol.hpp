#pragma once

#include <iostream>

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentage, size_t basePercentage);
    Alcohol(std::string name, size_t percentage);
    ~Alcohol() override;

    // Override from Cargo
    double getPrice() const override;
    size_t getBasePercentage() const;
    size_t getPercentage() const;
    virtual std::shared_ptr<Cargo> clone() const;

    // Override from Cargo
    bool operator==(const Cargo& cargo) const override;

    friend std::ostream& operator<<(std::ostream& os, const Alcohol& obj);

private:
    const size_t percentage_;
    const size_t basePercentage_= 10;
};
