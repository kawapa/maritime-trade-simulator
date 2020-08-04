#pragma once

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentage, size_t basePercentage);
    ~Alcohol() override;

    // Override from Cargo
    double getPrice() const override;
    size_t getPercentage() const;

    // Override from Cargo
    bool operator==(const Cargo& cargo) const override;

private:
    const size_t percentage_;
    const size_t basePercentage_;
};
