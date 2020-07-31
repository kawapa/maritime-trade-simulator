#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(size_t amount, std::string name, size_t basePrice, size_t timeToRot, size_t shelfLife);
    ~Fruit() override;

    // Override from Cargo
    virtual double getPrice() const override;
    virtual std::string getName() const override;
    virtual size_t getAmount() const override;
    virtual size_t getBasePrice() const override;
    size_t getTimeToRot() const;

    // Override from Cargo
    virtual Cargo& operator+=(const size_t amount) override;
    virtual Cargo& operator-=(const size_t amount) override;
    virtual bool operator==(const Cargo& cargo) const override;

    virtual Fruit& operator--();
    virtual Fruit operator--(int);
    
private:
    size_t timeToRot_;
    const size_t shelfLife_;
};
