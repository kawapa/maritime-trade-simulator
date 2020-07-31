#pragma once

#include "Cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentage, size_t basePercentage);
    ~Alcohol() override;

    // Override from Cargo
    double getPrice() const override;
    std::string getName() const override;
    size_t getAmount() const override;
    size_t getBasePrice() const override;

    size_t getPercentage() const;

    bool operator==(const Cargo& cargo) const override;
    Cargo& operator+=(const size_t amount);
    Cargo& operator-=(const size_t amount);

private:
    const size_t percentage_;
    const size_t basePercentage_;
};
