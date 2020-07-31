#pragma once

#include <string>

class Cargo {
public:
    Cargo(size_t amount, std::string name, size_t basePrice);
    virtual ~Cargo();

    virtual double getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual size_t getBasePrice() const = 0;
    void nextDay();

    virtual Cargo& operator+=(const size_t amount) = 0;
    virtual Cargo& operator-=(const size_t amount) = 0;
    virtual bool operator==(const Cargo& cargo) const = 0;

protected:
    size_t amount_;
    const std::string name_;
    size_t basePrice_;
};
