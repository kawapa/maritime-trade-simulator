#pragma once
#include "Fruit.hpp"

class DryFruit : public Fruit {
public:
    DryFruit(size_t, std::string, size_t, size_t, size_t);
    ~DryFruit() override;

    // Override from Fruit
    virtual double getPrice() const override;
    virtual std::string getName() const override;
    
    bool operator==(const Cargo& cargo) const override;

private:

};