#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(size_t amount, std::string name, size_t basePrice, size_t timeToRot, size_t shelfLife);
    ~Fruit() override;

    // Override from Cargo
    virtual double getPrice() const override;
    size_t getTimeToRot() const;

    // Override from Cargo
    virtual bool operator==(const Cargo& cargo) const override;

    virtual Fruit& operator--();
    virtual Fruit operator--(int);
    
private:
    size_t timeToRot_;
    const size_t shelfLife_;
};
