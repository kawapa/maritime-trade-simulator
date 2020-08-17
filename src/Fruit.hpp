#pragma once

#include "Cargo.hpp"

class Fruit : public Cargo {
public:
    Fruit(size_t amount, std::string name, size_t basePrice, size_t timeToRot, size_t shelfLife);
    virtual ~Fruit() override;

    // Override from Cargo
    virtual double getPrice() const override;
    size_t getTimeToRot() const;
    size_t getShelfLife() const;

    // Override from Cargo
    virtual bool operator==(const Cargo& cargo) const override;
    virtual Fruit& operator--();
    virtual Fruit operator--(int);
    virtual std::shared_ptr<Cargo> clone() const;

    friend std::ostream& operator<<(std::ostream& os, const Fruit& obj);

protected:
    size_t timeToRot_;
    const size_t shelfLife_;
};
