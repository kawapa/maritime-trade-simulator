#pragma once

#include <string>

class Cargo {
public:
    Cargo(size_t amount, std::string name, size_t basePrice);
    virtual ~Cargo();

    virtual double getPrice() const = 0;
    std::string getName() const;
    size_t getAmount() const;
    size_t getBasePrice() const;

    virtual Cargo& operator+=(const size_t amount);
    virtual Cargo& operator-=(const size_t amount);
    virtual bool operator==(const Cargo& cargo) const = 0;

protected:
    size_t amount_;
    const std::string name_;
    size_t basePrice_;
};
